# we want to maximize our log returns
import random
import math
import numpy as np
import scipy.stats as st

class Game:
	def __init__(self, n_cards=63):
		self.n_cards = n_cards
		self.cards = []
		
		self.removed = []

		for i in range(self.n_cards):
			self.cards.append(i % 10 + 1)

	def get_random_card(self) -> int:
		card = random.choice(self.cards)
		self.cards.remove(card)
		self.removed.append(card)
		return card
	
	# two assets we want to trade the most
	def get_even_price(self):
		return np.prod([x for x in self.removed if x % 2 == 0])

	def get_odd_price(self):
		return np.prod([x for x in self.removed if x % 2 == 1])

class MM:
	def __init__(self):
		self.cards = []

	def receive(self, card: int) -> int:
		self.cards.append(card)
		return card

	def should_trade_even(self) -> bool:
		even_ev = sum(math.log(x) for x in self.cards if x % 2 == 0)
		odd_ev = sum(math.log(x) for x in self.cards if x % 2 != 0)
		return even_ev >= odd_ev

	# takes in tuple of (ours, remaining)
	# remaining rounds = number of unaccounted cards -> could be players
	def calculate_ci_prod(self, cards, remaining_rounds, even: bool, alpha=0.95):
		# normalization for even/odd
		remaining_rounds /= 2

		ours = sum([math.log(x) for x in self.cards if x % 2 == (0 if even else 1)])

		log_rem = np.array([math.log(x) for x in cards])
		cards_mu = np.mean(log_rem) * remaining_rounds
		cards_std = np.std(log_rem) / np.sqrt(remaining_rounds)

		interval = st.t.interval(alpha=alpha, df=len(cards) - 1, loc=ours + cards_mu, scale=cards_std)

		return np.exp(interval)


if __name__ == "__main__":
	mm = MM()
	game = Game()

	even_ci = None
	odd_ci = None

	for i in range(0, 9):
		print()
		received = mm.receive(game.get_random_card())
		print("game state:", game.removed)
		print("received: ", received)

		even = mm.should_trade_even()
		print("we trade even: ", even)
		ci = mm.calculate_ci_prod(game.cards, 10 - i - 1, even)
		print("calculated ci: ", ci)

		if even:
			print("true value: ", game.get_even_price())
			even_ci = ci
		else:
			print("true value: ", game.get_odd_price())
			odd_ci = ci

	received = mm.receive(game.get_random_card())
	print("final even ci: ", even_ci, ", true value: ", game.get_even_price())
	print("final odd ci: ", odd_ci, ", true value: ", game.get_odd_price())
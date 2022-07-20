import itertools

possibilites = ["df$popThous", "df$popDensity",
                "df$lifeExp", "df$cellsPerHund", "df$yrsSchoolFM", "df$CO2"]

for _ in range(0, len(possibilites)):
    for selection in itertools.combinations(possibilites, _):
        if(len(selection) == 0):
            continue
        print(f"""print("===== {selection} =====")

dflm <- lm(df$lifeExp ~ {" + ".join(selection)})
dflmAug <- augment(dflm)

dflmAug %>% ggplot(aes(x = .resid)) +
  geom_histogram(binwidth = 1, fill = 'light blue', col = 'black') +
  labs(title = "Residuals")

dflmAug %>% ggplot(aes(x= .fitted, y = .resid)) +
  geom_hline(yintercept = 0) +
  geom_point(col='blue') +
  labs(x = "Fitted", y = "Residual", title = "Residuals vs Fitted")

tidy(dflm)
glance(dflm)\n""")
# command line utility to move cp files to sorted folders
import os
from datetime import datetime

root = "./"
sorted_directory = "./contest/"
file_extensions = ['.cpp']
prefix = "// [auto_folder]: "
shortcuts = {"cf": "codeforces"}

files = [f for f in os.listdir(root) if os.path.isfile(os.path.join(root, f))]
files = list(filter(lambda x : any([ext in x for ext in file_extensions]), files))

for file_name in files:
	with open(file_name) as f:
		print(file_name)
		first_line = f.readline()

		# filter prefix
		if prefix not in first_line:
			continue

		dest_name = first_line.replace(prefix, "").replace("\n", "")

		if dest_name in shortcuts:
			dest_name = shortcuts[dest_name]
		if len(dest_name) == 0:
			dest_name = "other"

		dest_path = f"{sorted_directory}{dest_name}/{dest_name}_{datetime.today().strftime('%Y_%m_%d')}_{file_name}"

		os.rename(file_name, dest_path)
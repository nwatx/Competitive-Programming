import os
import shutil
import re

CONTENT = "C:/Users/wangg/OneDrive/Documents/GitHub/CP/templates/implementations/content"
SNIPPETLOCATION = "C:/Users/wangg/OneDrive/Documents/GitHub/CP/scripts/output/"

if os.path.exists(SNIPPETLOCATION):  # remove LOC if it already exists
    shutil.rmtree(SNIPPETLOCATION)
os.makedirs(SNIPPETLOCATION)  # make LOC

print("SNIPPETS LOCATION:\n\n", SNIPPETLOCATION.replace(' ', '\\ '), '\n')

snippet = ""
temp = ""


def getPath(short):
    return SNIPPETLOCATION+"benqpreview.code-snippets"

with open(getPath(""), 'w') as fout:
    fout.write('{\n')

def jsonformat(description):
    return description.replace('\\', '\\\\').replace('\n', ',').replace('\t', " ").replace('"', "\\\"")

def createSnippet(name, prefix, body, description):
    # print(body)
    body = body.replace('\\', '\\\\')
    body = body.replace('"', '\\\"')
    body = body.replace('\n', '","')
    body = body.replace('\t', '\\t')
    snip = f'\t"{name}": {{\n\t\t"prefix":[ "{prefix}" ],\n\t\t"body": ["{body}"],\n\t"description":"{jsonformat(description)}"}},\n'
    return snip

def getDescription(code):
    desc = re.search("(?<=Description:)((.|\n)*)(?=Source:)", code)
    if(not desc is None):
        return desc.group(0).strip()
    return "None"

def output(short, code):  # write "code" to sublime snippet with trigger "short"
    with open(getPath(short), "a") as fout:
        fout.write(createSnippet(short, short, code, getDescription(code)))
def getNorm(pre): # format code
	blank = False
	res = ""
	for a in pre.split('\n'):
		if not a.endswith('\n'): 
			a += '\n'
		if '#pragma once' in a:
			continue
		if len(a) <= 1:
			if not blank:
				res += a
			blank = True
		else:
			blank = False
			res += a.replace('$','\\$')
	while res[-1] == '\n': # remove trailing blank lines
		res = res[:-1]
	return res

def checkNorm(root,name): # read file into string and format it
	res = ""
	with open(os.path.join(root, name),"r") as fin:
		for a in fin:
			res += a
	return getNorm(res)

def process(root, name):
    global snippets, temp, modint_template, modfact_template
    print(name)

    def shorten(name):
        short = name[:name.rfind('.')]
        if '(' in short:
            short = short[:short.find('(')]  # remove parentheses
        short = short.rstrip()
        return short
    if name.endswith(".h"):
        if name[0].isupper():
            print("INCLUDED:", name)
            output(shorten(name), checkNorm(root, name))
        elif "old" not in name.lower() and "kactl" not in name.lower():
            print("NOT INCLUDED:", name)
    if name.endswith("ModInt.h"):
        modint_template = checkNorm(root, name)
    if name.endswith("ModFact.h"):
        modfact_template = checkNorm(root, name)
    if name.endswith(".cpp"):
        if "TemplateLong" in name:
            print("TEMPLATE_LONG:", name)
            temp = tempLong(root, name)
            output("Temp", temp)
        elif "TemplateShort" in name:
            print("TEMPLATE_SHORT:", name)
            output("TempShort", tempShort(root, name))
        elif "usaco" in name or "Template" in name:
            print("INCLUDED:", name)
            output(shorten(name).replace(
                "Template", "Temp"), tempLong(root, name))
        elif "template" not in name.lower() and "test" not in name.lower():
            print("NOT INCLUDED:", name)
    if name == "Snippets.md":
        snippets = os.path.join(root, name)
    if name == "stress.sh":
        global suf
        _suf = suf
        # https://gist.github.com/J2TeaM/a54bafb082f90c0f20c9
        suf = suf.replace('.c++', '.shell')
        print("INCLUDED", "stress.sh")
        output("stress", checkNorm(root, name))
        suf = _suf


for root, dirs, files in os.walk(CONTENT, topdown=False):
    for name in files:
        process(root, name)

with open(getPath(""), 'a') as fout:
    fout.write('\n}')
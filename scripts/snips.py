import os
import json
import argparse
import re

def extract_snippets_from_file(file_path):
    with open(file_path, 'r') as file:
        content = file.read()

    # Regex to match the snippet structure
    pattern = re.compile(r'// (.*?)\n// (.*?)\n(.*)', re.DOTALL | re.MULTILINE)
    matches = pattern.findall(content)

    snippets = {}
    for match in matches:
        prefix, description, body = match
        name = body.split(' ')[1]  # Assuming the name is the second word in the body definition
        snippets[name] = {
            "prefix": "my_" + prefix,
            "body": body.split('\n'),
            "description": description
        }
    return snippets
    

def generate_code_snippets(input_dir, output_file):
    snippets = {}
    for root, dirs, files in os.walk(input_dir):
        for file in files:
            if not file.endswith('.cpp'):  # Assuming code files are .cpp, change this as necessary
                continue
            file_path = os.path.join(root, file)
            file_snippets = extract_snippets_from_file(file_path)
            snippets.update(file_snippets)

    if not snippets:
        raise ValueError("No valid snippets found in the provided directory.")

    with open(output_file, 'w') as file:
        json.dump(snippets, file, indent=4)

# python3 scripts/snips.py implementations .vscode/my.code-snippets
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Generate code snippets from a directory.')
    parser.add_argument('input_dir', type=str, help='Input directory containing code files.')
    parser.add_argument('output_file', type=str, help='Output .code-snippets file.')

    args = parser.parse_args()

    generate_code_snippets(args.input_dir, args.output_file)

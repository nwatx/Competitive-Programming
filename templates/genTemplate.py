import requests
from tqdm import tqdm

TEMPLATE_LONG='https://raw.githubusercontent.com/bqi343/USACO/master/Implementations/content/contest/TemplateLong.cpp'

TEMPLATE_SHORT='https://raw.githubusercontent.com/bqi343/USACO/master/Implementations/content/contest/TemplateShort.cpp'

TEMPLATE_VERY_SHORT='https://raw.githubusercontent.com/bqi343/USACO/master/Implementations/content/contest/TemplateVeryShort.cpp'

LONG_OUTPUT_PATH='C:/Users/wangg/OneDrive/Documents/GitHub/CP/templates/LONG.cpp'
SHORT_OUTPUT_PATH='C:/Users/wangg/OneDrive/Documents/GitHub/CP/templates/SHORT.cpp'
VERY_SHORT_OUTPUT_PATH='C:/Users/wangg/OneDrive/Documents/GitHub/CP/templates/VERYSHORT.cpp'

ITER={TEMPLATE_LONG:LONG_OUTPUT_PATH, TEMPLATE_SHORT:SHORT_OUTPUT_PATH, TEMPLATE_VERY_SHORT:VERY_SHORT_OUTPUT_PATH}

# VERY_SHORT = requests.get(TEMPLATE_VERY_SHORT, stream=True)

for URL in ITER:
    URL_CONTENT = str(requests.get(URL, stream=True).content).replace('\\n', '\n').replace('\\t', '\t').replace("\\'","'")
    with open(ITER[URL], 'w') as fout:
        fout.write(URL_CONTENT[2:-1])

# with open(VERY_SHORT_OUTPUT_PATH, 'w') as fout:
#     print(str(VERY_SHORT.content).replace('\\n', '\n').replace('\\t', '\t'))
#     fout.write(str(VERY_SHORT.content))
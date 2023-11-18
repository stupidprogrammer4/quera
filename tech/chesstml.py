from bs4 import BeautifulSoup
def process(path):
    with open(path) as f:
        html = f.read()
    soup = BeautifulSoup(html, 'html.parser')
    links = soup.find_all('a')
    return len(links)


print(process("htmlsampletest1.html"))

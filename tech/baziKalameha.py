import re, math


def is_bad_word(word):
    return re.findall('[^A-Za-z]', word).__len__() >= math.ceil(len(word)/2)

def words_check(text):
    result = {}
    words = text.split()
    for word in words:
        if not is_bad_word(word):
            word = re.sub('[^A-Za-z]', '', word).capitalize()
            if result.get(word):
                result[word] += 1
            else:
                result[word] = 1

    return result

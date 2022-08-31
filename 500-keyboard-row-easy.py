from typing import List


def func(words: List[str]) -> List[str]:
    kb = {
        'q': 0, 'w': 0, 'e': 0, 'r': 0, 't': 0, 'y': 0, 'u': 0, 'i': 0, 'o': 0, 'p': 0,
        'a': 1, 's': 1, 'd': 1, 'f': 1, 'g': 1, 'h': 1, 'j': 1, 'k': 1, 'l': 1,
        'z': 2, 'x': 2, 'c': 2, 'v': 2, 'b': 2, 'n': 2, 'm': 2,
    }
    res = []
    for word in words:
        curr_row = None
        isGood = True
        for ch in word:
            ch = ch.lower()
            if curr_row is None:
                curr_row = kb[ch]
            else:
                if curr_row != kb[ch]:
                    isGood = False
                    break
        if isGood:
            res.append(word)
    return res


if __name__ == "__main__":
    print(func(["Hello", "Alaska", "Dad", "Peace"]))
    # output : ["Alaska", "Dad"]

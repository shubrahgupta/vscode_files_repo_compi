import operator
import sndhdr
import string
import sys

# def my(e):
#     return e

def main():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
    clues = []
    for i in range(4):
        s = str(input())
        clues.append(s)
    # print(s)
    a = {}
    for i in range(len(s)):
        if s[i] in a:
            a[s[i]] = a[s[i]] + 1
        else:
            a[s[i]] = 1
    
    sorted_a = dict(
        sorted(a.items(), key=operator.itemgetter(1), reverse=True))
    l = list(sorted_a.keys())
    for i in range(3):
        print(l[i],sorted_a[l[i]])








if __name__ == "__main__":
    main()
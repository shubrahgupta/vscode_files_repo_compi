import sndhdr
import string
import sys

# def nigga(board):
#     mydict = {}
#     mydict2 = {}
    
#     for i in range(9):
#         mydict.clear()
#         mydict2.clear()
#         for j in range(9):
#             if board[i][j] != "." and board[i][j] not in mydict:
#                 mydict[board[i][j]] = 1
#             elif board[i][j] != "." and board[i][j] in mydict:
#                 return False

#             if board[j][i] != "." and board[j][i] not in mydict2:
#                 mydict2[board[j][i]] = 1
#             elif board[j][i] != "." and board[j][i] in mydict2:
#                 return False

#     for i1 in range(3):
#         for j1 in range(3):
#             mydict.clear()
#             for i2 in range(3):
#                 for j2 in range(3):
#                     if board[3*i1 + i2][3*j1 + j2] != "." and board[3*i1 + i2][3*j1 + j2] not in mydict:
#                         mydict[board[3*i1 + i2][3*j1 + j2]] = 1
#                     elif board[3*i1 + i2][3*j1 + j2] != "." and board[3*i1 + i2][3*j1 + j2] in mydict:
#                         return False

#     return True


# def isAnagram(s,t):
    # if len(s) != len(t):
    #     return False
    # else:
    #     mydict = {}
    #     mydict1 = {}
    #     for i in range(len(s)):
    #         if s[i] in mydict:
    #             mydict[s[i]] += 1
    #         else:
    #             mydict[s[i]] = 1
            
    #     for i in range(len(t)):
    #         if t[i] in mydict1:
    #             mydict1[t[i]] += 1
    #         else:
    #             mydict1[t[i]] = 1

    #     for i in range(len(t)):
    #         if t[i] in mydict:

    #             if mydict1[t[i]] != mydict[t[i]]:
    #                 return False
    #         else:
    #             return False
    #     return True


def bulla(s,t):
    mydict = {}
    mydict1 = {}
    s1 = list(set(s))

    for i in range(len(s)):
        if s[i] not in mydict:
            mydict[s[i]] = 1
        else:
            mydict[s[i]] += 1

    for i in range(len(t)):
        if t[i] not in mydict1:
            mydict1[t[i]] = 1
        else:
            mydict1[t[i]] += 1
    op = 0

    for i in range(len(s1)):
        if s1[i] in mydict1:
            if mydict[s1[i]] != mydict1[s1[i]]:
                op += abs(mydict1[s1[i]] - mydict[s1[i]])
        else:
            s2 = list(set(s) ^ set(t))
            op += len(s2)
    return op



def main():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


    q = int(input())


    while q != 0 :
        s = input()
        t = input()
        op = bulla(s,t)

        # print(op)
        s = ''.join(sorted(s))
        t = ''.join(sorted(t))
        res = t.replace(s, '')
        # s
        print(res)
        # diff = ", ".join(diff)

        q = q-1




if __name__ == "__main__":
    main()
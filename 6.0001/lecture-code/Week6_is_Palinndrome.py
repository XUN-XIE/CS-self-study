def isPalindrome(s):

    def toChars(s):
        s = s.lower()
        letters = ''
        for c in s:
            if c.isalpha():
                letters += c

        return letters
    
    def isPal(s):
        print("isPal called with " + s)
        if len(s) <= 1:
            print("About to return True from base case")
            return True
        else:
            answer = s[0] == s[-1] and isPal(s[1:-1])
            print("About to return " + str(answer) + " for " + s)
            return answer

    return isPal(toChars(s))

def testIsPalindrome():
    print("Try dogGod")
    print(isPalindrome("dogGod"))
    print("Try doGood")
    print(isPalindrome("doGood"))

if __name__ == "__main__":
    testIsPalindrome()
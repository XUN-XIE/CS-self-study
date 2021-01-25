x = 25
numGuess = 0
epsilon = 0.01
ans = 0.0

low = 0.0
high = max(1.0, x)

while abs(ans**2 - x) >= epsilon:
    print('low = ' + str(low) + ', high = ' + str(high) + ', ans = ' + str(ans))
    numGuess += 1

    if ans ** 2 < x:
        low = ans
    else:
        high = ans
    ans = (high + low) / 2

print("numGuess = "+ str(numGuess))
print(str(ans) + " is close to square root of " + str(x))

x = -8
numGuess = 0
epsilon = 0.01
ans = 0.0

if x >= 0:
    low = 0.0
    high = max(1.0, x)
else:
    low = min(-1.0, x)
    high = 0.0

while abs(ans**3 - x) >= epsilon:
    print('low = ' + str(low) + ', high = ' + str(high) + ', ans = ' + str(ans))
    numGuess += 1

    if ans ** 3 < x:
        low = ans
    else:
        high = ans
    ans = (high + low) / 2

print("numGuess = "+ str(numGuess))
print(str(ans) + " is close to cubic root of " + str(x))

x = 25
numGuess = 0
epsilon = 0.01
step = epsilon**2
ans = 0.0

while abs(ans**2 - x) >= epsilon and ans <= x:
    ans += step
    numGuess += 1

print("numGuess = "+ str(numGuess))
if abs(ans**2 - x) >= epsilon:
    print("Failed on square root of " + str(x))
else:
    print(str(ans) + " is close to square root of " + str(x))

# # Part A
# print("Enter your annual salary:")
# annual_salary = float(input())

# print("Enter the percent of your salary to save, as a decimal:")
# portion_saved = float(input())

# print("Enter the cost of your dream home:")
# total_cost = float(input())

# portion_down_payment = 0.25
# current_savings = 0
# r = 0.04

# num_month = 0
# while current_savings < total_cost * portion_down_payment:
#     current_savings += annual_salary / 12.0 * portion_saved + current_savings * r / 12.0
#     num_month += 1

# print("Number of months:" + str(num_month))


# # PART B
# print("Enter your annual salary:")
# annual_salary = float(input())

# print("Enter the percent of your salary to save, as a decimal:")
# portion_saved = float(input())

# print("Enter the cost of your dream home:")
# total_cost = float(input())

# print("Enter the semi-annual salary raise:")
# semi_annual_raise = float(input())

# portion_down_payment = 0.25
# current_savings = 0
# r = 0.04

# num_month = 0
# while current_savings < total_cost * portion_down_payment:
#     current_savings += annual_salary / 12.0 * portion_saved + current_savings * r / 12.0
#     num_month += 1

#     if num_month % 6 == 0:
#         annual_salary += annual_salary * semi_annual_raise

# print("Number of months:" + str(num_month))


# Part C
portion_down_payment = 0.25
r = 0.04
semi_annual_raise = 0.07

epsilon = 100
total_cost = 1e6 
target = total_cost * portion_down_payment
num_month = 36

print("Enter your annual salary:")
annual_salary = float(input())

def final_savings(portion_saved):
    salary = annual_salary
    current_savings = 0
    for i in range(1,num_month + 1):
        if i % 6 == 0:
            salary += salary * semi_annual_raise
        current_savings += salary / 12.0 * portion_saved + current_savings * r / 12.0
    
    return current_savings

trial = 0.0
low = 0.0
high = 1.0

trial_value = final_savings(trial)

step = 0
bool = 1
while abs( trial_value - target ) > epsilon:
    if trial_value > target:
        high = trial
    else:
        low = trial
    trial = (low + high) / 2
    trial_value = final_savings(trial)
    
    if trial == 1 and trial_value - target < 0:
        print("It is not possible too pay the down payment in three years")
        bool = 0
        break
        
    step += 1

if bool:
    print("Best savings rate:" + str(round(trial, 4)))
    print("Steps in bisection search: " + str(step))

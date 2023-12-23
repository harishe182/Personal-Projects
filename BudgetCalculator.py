print("University Monthly Budget Calculator")
saving = float(input('Enter savings: '))
income = float(input('Enter post-tax income (CAD): '))
additional = float(input('Enter additional income: '))

total_assets = additional + income + saving
print("Your total income is $" + str(total_assets))

def gather_expenses():
    Rent = float(input('Enter rent expenses: '))
    Food = float(input('Enter food expenses: '))
    Entertainment = float(input('Enter entertainment expenses: '))
    Transportation = float(input('Enter transportation expenses: '))
    Other = float(input('Enter other expenses: '))
    total_expenses = Rent + Food + Entertainment + Transportation + Other
    return total_expenses

expense_total = gather_expenses()

# Calculate the margin here
margin = total_assets - expense_total

print("Your Total expenses are $" + str(expense_total))

if margin > 0:
    print("You saved $" + str(margin))
elif margin == 0:
    print("You broke even")
else:
    print("You are down $" + str(-margin))

print("Thanks for using University Budget Calculator")
from expense import Expense
import calendar
import datetime

def main():
    print("Running Expense Tracker!")
    expense_file = "expenses.csv"
    budget = 200

    # Get user expenses 
    expense = get_user_expense()

    # Write their expense to a file
    write_expense(expense,expense_file)

    # Read file and summarize expenses
    read_expense(expense_file, budget)

def get_user_expense():
    print('Getting User Expenses')
    expense_name = input("Enter expense name: ")
    expense_amount = float(input("Enter expense amount: $"))
    print(f"You've entered {expense_name}: ${expense_amount}")

    expense_categories = [
        'Food', 
        'Home', 
        'Work', 
        'Fun', 
        'Misc'
    ]

    while True:
        print('Select a category: ')
        for i, category_name in enumerate(expense_categories):
                print(f'   {i + 1}. {category_name}')

        value_range = f"[1 - {len(expense_categories)}]"
        selected_index = int(input(f"Enter a category number {value_range}: ")) - 1

        if selected_index in range(len(expense_categories)):
            selected_category = expense_categories[selected_index]
            new_expense = Expense(
                 name = expense_name, category=selected_category, amount=expense_amount
                 )
            return new_expense
        else:    
             print("Invaild Category. Try again")

def write_expense(expense: Expense, expense_file):
    print(f'Saving User Expenses: {expense}')
    with open(expense_file, 'a') as f:
         f.write(f"{expense.name}, {expense.amount}, {expense.category}\n")
         

def read_expense(expense_file, budget):
    print('Summarizing User Expenses')
    expenses = []
    with open(expense_file, 'r') as f:
         lines = f.readlines()
         for line in lines:
            stripped_line = line.strip()
            expense_name, expense_amount, expense_category = stripped_line.split(",")
            print(expense_name, expense_amount, expense_category)
            line_expense = Expense(
                 name=expense_name, amount=float(expense_amount), category=expense_category 
            )
            expenses.append(line_expense)

    amount_by_category = {}
    for expense in expenses:
         key = expense.category
         if key in amount_by_category:
              amount_by_category[key] += float(expense_amount)
         else:
            amount_by_category[key] = expense.amount
    
    print("Expense By Category; ")       
    for key, amount in amount_by_category.items():
        print(f"   {key}: ${amount:.2f}")

    total_spent = sum([x.amount for x in expenses])
    print(f"You've spent ${total_spent:.2f} this month!")

    remaining_budget = budget - total_spent
    print(f"Budget Remaining: ${remaining_budget:.2f}")

    now = datetime.datetime.now()
    days_in_month = calendar.monthrange(now.year, now.month)[1]
    remaining_days = days_in_month - now.day
    print("Remaining days in the current month: ", remaining_days)

    daily_budget = remaining_budget / remaining_days
    print(green(f"Budget Per Day: ${daily_budget:.2f}"))

def green(text):
    return f"\033[92m{text}\033[0m"


if __name__ == "__main__":
    main()
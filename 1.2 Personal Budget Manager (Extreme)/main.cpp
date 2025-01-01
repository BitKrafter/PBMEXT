#include <iostream> 
#include <vector>
#include <numeric>
#include <string>


//objects and variables from the standard library

using namespace std;

// to store subcategory , category , expense
struct ExpenseItem {

    string Category;
    string Subcategory;
    int expense;

};

// Function to display expenses 
// const used for not modifying  the vector
// & Used for referencing expense items structure in this function 
void DisplayExpenses (const vector<ExpenseItem>& expenses ) {

        cout << "\n--- Current Expenses---\n";
        for (int i=0; i < expenses.size(); i++ ){
        cout << (i + 1) <<". " << expenses[i].Category << " (" << expenses[i].Subcategory << ") :$" << expenses[i].expense << endl;

    }    

}


//Function to add expenses and cautionary line of code written aswell
void AddExpenses(vector <ExpenseItem>& expenses){

        ExpenseItem NewExpense;

         cout << "Enter Category ( for ex: Food, Transportation , etc. ): " ;
        cin >> NewExpense.Category;

        cout << "Enter Subcategory ( For ex: Groceries for food or Gas for Transportation): ";
        cin >> NewExpense.Subcategory;

        cout << "Enter Expense :$" ;
        cin >> NewExpense.expense ;

        while (NewExpense.expense <= 0 ) {

            cout << " Please Enter Valid Expense for " << NewExpense.Category << " - " << NewExpense.Subcategory << ": $" ;
            cin >> NewExpense.expense;

        }

        //adds new expense to list 
        expenses.push_back(NewExpense); 

}

// Function to delete expenses
void DeleteExpenses (vector <ExpenseItem>& expenses){

        DisplayExpenses (expenses);
        int index;

        cout << "\nEnter the number of the expense you want to delete: ";
        cin >> index;

        if (index > 0 && index <= expenses.size()) {
        expenses.erase(expenses.begin() + index - 1);  // Delete the selected expense
        cout << "Expense deleted successfully.\n";
    } else {
        cout << "Invalid expense number.\n";

    }

} 

void EditExpenses (vector <ExpenseItem>& expenses){

     DisplayExpenses(expenses);

    int index;
    cout << "\nEnter the number of the expense you want to edit: ";
    cin >> index;

    if (index > 0 && index <= expenses.size()) {
        int choice;
        cout << "What would you like to edit?\n";
        cout << "1. Category\n";
        cout << "2. Subcategory\n";
        cout << "3. Expense amount\n";
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter new Category: ";
            cin >> expenses[index - 1].Category;
        } else if (choice == 2) {
            cout << "Enter new Subcategory: ";
            cin >> expenses[index - 1].Subcategory;
        } else if (choice == 3) {
            cout << "Enter new Expense amount: $";
            cin >> expenses[index - 1].expense;

            // Validation for valid expense
            while (expenses[index - 1].expense <= 0) {
                cout << "Please enter a valid amount: $";
                cin >> expenses[index - 1].expense;
            }
        } else {
            cout << "Invalid choice.\n";
        }
        cout << "Expense updated successfully.\n";
    } else {
        cout << "Invalid expense number.\n";
    }
}


int main() {
    
    //Iniatialising these Integers

    int Monthly_Budget;
    int Count;

    // Ask for number of months
    int Total_Months;
    cout << "Enter Numbers Of Months To Track Your Budget : ";
    cin >> Total_Months;

    //Just a precationary line of code to help others 
    while ( Total_Months <= 0) {

        cout << "Please Enter A Valid Numbers Of Months: ";
        cin >> Total_Months;
    }

    int Remaining_Budget = 0;
    int T_E_A_M = 0;

    // A for loop for the label month  or month 2
    for (int month = 1 ; month <= Total_Months ; ++month) {
    cout << "\n--- Month" << month << " ---\n" ; 

    //Asking Budget

    std::cout << "Enter Monthly Budget :$ ";
    std::cin >> Monthly_Budget;

    //Cautionary while loop helping if negative or zero value given

    while (Monthly_Budget <=0){

        std::cout << "Please Enter A Valid Amount :$ " << std::endl;
        std::cin >> Monthly_Budget;
    }
    
    //Entering The Number Of Expenses

        std::cout << "How many expenses would you like to submit?: " ;
        std::cin >> Count;

    // Same Thing Here Again

    while (Count <=0){

        std::cout << "Please Enter A Valid Amount : " << std::endl;
        std::cin >> Count;
    }

    //Creating vectors for ExpenseItem

    vector <ExpenseItem> Expenses ( Count ); 


    // loop to ask about categories, subcategory and expenses and precaution added aswell

    for (int i=0 ; i< Count ; i++){

        cout << "Enter Category ( for ex: Food, Transportation , etc. ): " ;
        cin >> Expenses[i].Category;

        cout << "Enter Subcategory ( For ex: Groceries for food or Gas for Transportation): ";
        cin >> Expenses[i].Subcategory;

        cout << "Enter Expense :$" ;
        cin >> Expenses[i].expense ;

    // While has its own bracket remember

    while ( Expenses[i].expense <= 0 ){    

        cout << "Enter Valid Expense For " << Expenses[i].Category << " - " << Expenses[i].Subcategory << " :$" << endl;
        cin >> Expenses[i].expense ;
        }

    }


     int choice;
        while (true) {
            cout << "\nSelect an action:\n";
            cout << "1. View Expenses\n";
            cout << "2. Add Expense\n";
            cout << "3. Delete Expense\n";
            cout << "4. Edit Expense\n";
            cout << "5. Finish Month and Calculate Total\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    DisplayExpenses(Expenses);
                    break;
                case 2:
                    AddExpenses(Expenses);
                    break;
                case 3:
                    DeleteExpenses(Expenses);
                    break;
                case 4:
                    EditExpenses(Expenses);
                    break;
                case 5:
                    goto finishMonth;
                    break;
                default:
                    cout << "Invalid option. Please try again.\n";
                    break;
            }
        }

        finishMonth:
        // Calculate total expenses for the month
        int sum = accumulate(Expenses.begin(), Expenses.end(), 0, [](int total, const ExpenseItem& item) {
            return total + item.expense;
        });
        
       /*This takes the first Element with .begin and through the last
        element with .end and it accumulates by adding the expenses and
        than that becomes sum*/

          int largest_expense = 0;
        string largest_category;
        string largest_subcategory;

        for (const auto& Expnse : Expenses) {
            if (Expnse.expense > largest_expense) {
                largest_expense = Expnse.expense;
                largest_category = Expnse.Category;
                largest_subcategory = Expnse.Subcategory;
            }
        }

    if (sum > Monthly_Budget){

        cout << "You Have exceed the budget upto : $" << sum - Monthly_Budget << endl;

     } else {

        cout << "The total expense is : $" << sum << endl;

        cout << "Remaining Budget For Current Month Is : $" << Monthly_Budget - sum << endl;

        //Carry over the remaining budget to next month

        Remaining_Budget = Monthly_Budget - sum;
        cout << "Remaining Budget To Carry Over To Next Month:$" << Remaining_Budget << endl;

        // Next months budget 
        int Next_Month_Budget;
        cout << " Enter Next Monthly Base Budget:$ ";
        cin >> Next_Month_Budget ;

        // just a precaution
        while (Next_Month_Budget <= 0) {
        cout << "Please Enter A Valid Base Budget For Next Month";
        cin >> Next_Month_Budget ;
        }

        Monthly_Budget = Next_Month_Budget + Remaining_Budget;
         cout << " The New Month Budget (Including Rollover) Is :$" << Monthly_Budget << endl;

            }

         // Display the largest expense
        cout << "The largest expense for this month was: $" << largest_expense << " in category " << largest_category << " (" << largest_subcategory << ")\n";

        }


    // Display the total expenses across all months
    cout << "\nTotal Expenses for " << Total_Months << " Months: $" << T_E_A_M << endl;

    return 0;

}
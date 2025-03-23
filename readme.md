
# Intro to OOP

**Software Development Yr1     Group Project – Semester 2 2025

---

This project is worth **60%** of your total marks for this module and is a team project.

Teams will consist of four students.

All members of each team are expected to make an equal contribution to the project and participate in all aspects of it, including problem development and analysis, coding, commenting of code and documentation. Teams should work together when possible and class time is an ideal opportunity to do this. Individual marks will be awarded where it is apparent that team members have not made an equal contribution to the project.

Note: Where it is obvious that a team member has made little or no contribution to the work effort of the project deliverables; this will result in a mark of zero.

The project solution must be uploaded to Moodle by Monday, **28/04/2025** no later than 5pm.

The project is based on the development of an application for managing a list of shopping items and will use a Class for the items. The specification for the application is given below.

You can produce the code to meet the minimum requirements of the project, butextramarksarereservedforadditionalfunctionality,such as error trapping and handling, etc. There is no limit to the length of the source code that you produce. Please note that marks will be deducted for poor programming practices, such as using unnecessary variables and bad naming conventions.

There are a number of factors that will be considered when the project is being graded, such as functionality, style, commenting and minimisation for the coding. All aspects of the project should be presented professionally and attention to detail is very important.

The design document must include details of your approach to software testing including sample test data together with expected and actual results. The design document must include a reflective piece from each student, in which you discuss how the team performed as a whole, what your contribution was, what you learned about all aspects of the project: team work, problem analysis, coding, what worked and could have been done better, etc.

**Specification for an item for a shopping application**

**TAG: CItem ATTRIBUTES:**

**int m\_Code**

**string m\_Description double m\_Price**

**double m\_DiscountRate**

**METHODS:**

**Constructors:**

A default constructor that takes no arguments. Will be used when instantiating a collection **CItem ( void )**

A ‘new item’ constructor that will be passed a code and description for an item. Will be used when adding new items to a collection.

**CItem(intcode,stringdescription)**

A ‘database constructor’ that will be passed data for all objectattributes. Will be used when persistent data is retrievedfromafileandthen usedtopopulateacollection.

**CItem (int code, string description, double price, double discountRate)**

**SetA’s** Seta functions should be added for some data members. **void SetPrice ( double price )**

**void SetDiscountRate(double discountRate)**

**GetA’s**

Will need a complete set of these. Will be needed when storing persistent data to a file **int GetCode (void)**

**string GetDescription (void)**

**double GetPrice (void)**

**double GetDiscountRate (void)**

**HasA’s** Will need to find items in a collection of items based on a code **bool HasCode ( int searchCode )**

**Implementors**

A function to display an items details

**void Display (void)**

A function to return the value of a discount available on an item price **double GetDiscount (void )**

**Part A**

The application will have item data for five items stored in a global collection of five objects of the **class CItem**asperthefollowingcode.

**CItem itemList[5];**

The application will have a text based menu‐driven system with a menu like this displayed. Please note that the final design of the menu is up to you, but should include this functionality at a minimum.

Item Menu

1. Initialize Price List
1. Display Full Price List
1. AddItemtoList
1. Set Item Price
1. Set Item Discount Rate
1. Display Item
1. OrderCost
1. Total Invoice
1. Remove Item from List
0. Quit

The application should contain a set of callback functions that should be called based on the option entered by the user.

The prototype for the callback functions will be: **void DoInitializePriceList(void);**

**void DoDisplayFullPriceList (void); voidDoAddItemToList(void);**

**void DoSetItemPrice (void);**

**void DoSetItemDiscountRate (void);**

**void DoDisplayItem(void);**

**void DoOrderCost(void);**

**void DoTotalInvoice(void);**

**void DoRemoveItemFromList(void);**

**void DoQuit(void);**

Write code for the functions:

1) **DoInitializePriceList** (callback for option 1)

   //if item list already exists, give the user the option of starting over, i.e. delete the existing //itemlistiftheywish

   //for new list, allow the user to enter all of the item details, construct the item object //and insert the item in the item list

2) **DoDisplayFullPriceList** (callback for option 2) //display a suitable item table header //display all of the items in the item list
2) **DoAddItemToList** (callback for option 3) //entercodeanddescriptionforthenewitem

   //constructtheitemobject

   //enterpriceanddiscountratefor the new item – enter zeros if not available //insert the new item in the item list

4) **DoSetItemPrice** (callback for option 4) //allowusertoenteritemcodeandprice //searchthecollectionforthematchingitemandsetitsprice
4) **DoSetItemDiscountRate** (callback for option 5) //allowusertoenteritem code and discount rate //searchthecollectionforthematchingitemandsetitsdiscount rate
4) **DoDisplayItem** (callback for option 6)

   //allow the user to enter an item code

   //search the collection for a matching item and display all item details

7) **DoOrderCost** (callback for option 7)

   //allow the user to enter item code and quantity //searchthecollectionforamatchingitem

   //ask if customer is to be given a discount

   //calculate the cost of the order (including discount if applicable) //display the total cost

8) **DoTotalInvoice** (callback for option 8)

//Calculate and display the total cost of all of the items in the collection

9) **DoRemoveItemFromList** (callback for option 9) //allow the user to enter an item code //searchthecollectionforamatchingitem

   //if matching item exists then remove it from the item list

10) **DoQuit** (callback for option 0) //Quitstheapplication

    **Part B**

    Adapt the application so that it could be used for item lists of **various sizes** up to a maximum of 25 items.

    **Part C** Addanadditionalclasstotheproject(**CUser**) that

1) Will require the user to enter a name and password
1) Will then check to see if a matching user exists
1) Will ascertain the user type
1) Will then display a user type appropriate menu

For testing purposes assume we have 3 users: 1 Manager and 2 Assistants

Username Password UserType Tom 1234 M

Fred 9876 A

Ger 4321 A

**TheFinal,completedprojectshould have the following options availableforboth Manager and Assistant Menus:**

**Manager Menu:**

1. Initialize Price List
1. Display Full Price List
1. Add Item to List 4.SetItemPrice
5. Set Item Discount Rate
5. Display Item
5. Order Cost
5. Total Invoice 9.RemoveItemfromList
10. Add User
10. Edit User
0. Quit

Note: Two additional Functions from part (A) now added to the Manager Menu **void DoAddUser(void)**

//enter name, password and user type for new user

//construct the user object and insert in the user list

**void DoEditUser(void)**

//allowsthepasswordtobechangedforanexistinguser

**Assistant Menu:**

1. Display Full Price List 2.SetItemPrice
3. Set Item Discount Rate
3. Display Item
3. Order Cost
3. Total Invoice

0\. Quit
7

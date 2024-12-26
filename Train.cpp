//Code For Airline Management 
#define _CRT_SECURE_NO_WARNINGS

// Airline Management System
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

string toLower(string str) {
  string lowerStr = str;

  for (size_t i = 0; i < str.length(); ++i) {
    lowerStr[i] = tolower((unsigned char)str[i]);
  }
  return lowerStr;
}

time_t t = time(NULL);
tm *timePtr = localtime(&t);

const int MAX_VALID_YR = timePtr->tm_year + 1901;
const int MIN_VALID_YR = timePtr->tm_year + 1900;

const int MIN_VALID_MNTH = timePtr->tm_mon + 1;
const int MAX_VALID_MNTH = timePtr->tm_mon + 2;

// Returns true if
// given year is valid.
bool isLeap(int year) {
  // Return true if year
  // is a multiple of 4 and
  // not multiple of 100.
  // OR year is multiple of 400.
  return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

// Returns true if given
// year is valid or not.
bool isValidDate(int d, int m, int y) {
  // If year, month and day
  // are not in given range
  if (y > MAX_VALID_YR || y < MIN_VALID_YR)
    return false;
  if (m < MIN_VALID_MNTH || m > MAX_VALID_MNTH)
    return false;
  if (d < 1 || d > 31)
    return false;

  // Handle February month
  // with leap year
  if (m == 2) {
    if (isLeap(y))
      return (d <= 29);
    else
      return (d <= 28);
  }

  // Months of April, June,
  // Sept and Nov must have
  // number of days less than
  // or equal to 30.
  if (m == 4 || m == 6 || m == 9 || m == 11)
    return (d <= 30);

  return true;
}

// Class for selecting Train destinationCitys of your choice

class TrainDetails {

  int TrainPNR[51] = {101,  102,  103,  122,  123,  124,  131,  132,  133,
                          241,  242,  243,  501,  502,  503,  601,  602,  603,
                          701,  702,  703,  801,  802,  803,  901,  902,  903,
                          1001, 1002, 1003, 1101, 1102, 1103, 1201, 1202, 1203,
                          1301, 1302, 1303, 1401, 1402, 1403, 1501, 1502, 1503,
                          1601, 1602, 1603, 1701, 1702, 1703};
  int price[51] = {12000, 10000, 15000, 11000, 14000, 10000, 12000, 13500,
                   9000,  12500, 14000, 12000, 16000, 16500, 13500, 14500,
                   12750, 14000, 15000, 18000, 16000, 15000, 17000, 16500,
                   12000, 10000, 15000, 11000, 14000, 10000, 12000, 13500,
                   9000,  12500, 14000, 12000, 16000, 16500, 13500, 14500,
                   12750, 14000, 15000, 18000, 16000, 15000, 17000, 16500,
                   12000, 10000, 15000};
  int selectTrain;
  int perPersonPrice;

public:
  void delhi() {
    cout << "\n\n Trains available for Delhi:";
    cout << "\n  " << TrainPNR[0] << "-Train (time: 5:00pm) " << price[0]
         << "/- per person";
    cout << "\n  " << TrainPNR[1] << "-Train (time: 12:00am) " << price[1]
         << "/- per person";
    cout << "\n  " << TrainPNR[2] << "-Train (time: 8:00pm) " << price[2]
         << "/- per person";

    cout << "\nChoose your Train: ";
    cin >> selectTrain;

    for (int i = 0; i <= 2; i++) {
      if (selectTrain == TrainPNR[i]) {
        setPerPersonPrice(price[i]);
        break;
      }
    }
  }

public:
  void bangalore() {
    cout << "\n You have chosen Bangalore.";
    cout << "\n Trains available for Bangalore:";
    cout << "\n  " << TrainPNR[3] << "-Train (time: 3:00pm) " << price[3]
         << "/- per person";
    cout << "\n  " << TrainPNR[4] << "-Train (time: 7:00pm) " << price[4]
         << "/- per person";
    cout << "\n  " << TrainPNR[5] << "-Train (time: 2:00am) " << price[5]
         << "/- per person";

    cout << "\n\nChoose your Train: ";
    cin >> selectTrain;

    for (int i = 3; i <= 5; i++) {
      if (selectTrain == TrainPNR[i]) {
        setPerPersonPrice(price[i]);
        break;
      }
    }
  }

public:
  void mumbai() {
    cout << "\n You have chosen Mumbai.";
    cout << "\n Trains available for Mumbai:";
    cout << "\n  " << TrainPNR[6] << "-Train (time: 4:00pm) " << price[6]
         << "/- per person";
    cout << "\n  " << TrainPNR[7] << "-Train (time: 9:00pm) " << price[7]
         << "/- per person";
    cout << "\n  " << TrainPNR[8] << "-Train (time: 2:00am) " << price[8]
         << "/- per person";

    cout << "\n\nChoose your Train: ";
    cin >> selectTrain;

    for (int i = 6; i <= 8; i++) {
      if (selectTrain == TrainPNR[i]) {
        setPerPersonPrice(price[i]);
        break;
      }
    }
  }

public:
  void chennai() {
    cout << "\n You have chosen Chennai.";
    cout << "\n Trains available for Chennai:";
    cout << "\n  " << TrainPNR[9] << "-Train (time: 1:00pm) " << price[9]
         << "/- per person";
    cout << "\n  " << TrainPNR[10] << "-Train (time: 3:00pm) " << price[10]
         << "/- per person";
    cout << "\n  " << TrainPNR[11] << "-Train (time: 2:00am) " << price[11]
         << "/- per person";

    cout << "\n\nChoose your Train: ";
    cin >> selectTrain;

    for (int i = 9; i <= 11; i++) {
      if (selectTrain == TrainPNR[i]) {
        setPerPersonPrice(price[i]);
        break;
      }
    }
  }

public:
  void kolkata() {
    cout << "\n Trains available for Kolkata:";
    cout << "\n  " << TrainPNR[12] << "-Train (time: 4:00am) " << price[12]
         << "/- per person";
    cout << "\n  " << TrainPNR[13] << "-Train (time: 3:00pm) " << price[13]
         << "/- per person";
    cout << "\n  " << TrainPNR[14] << "-Train (time: 6:00am) " << price[14]
         << "/- per person";

    cout << "\n\nChoose your Train: ";
    cin >> selectTrain;

    for (int i = 12; i <= 14; i++) {
      if (selectTrain == TrainPNR[i]) {
        setPerPersonPrice(price[i]);
        break;
      }
    }
  }

public:
  void ahmedabad() {
    cout << "\n Trains available for Ahmedabad:";
    cout << "\n  " << TrainPNR[15] << "-Train (time: 10:00am) "
         << price[15] << "/- per person";
    cout << "\n  " << TrainPNR[16] << "-Train (time: 3:20pm) " << price[16]
         << "/- per person";
    cout << "\n  " << TrainPNR[17] << "-Train (time: 1:00am) " << price[17]
         << "/- per person";

    cout << "\n\nChoose your Train: ";
    cin >> selectTrain;

    for (int i = 15; i <= 17; i++) {
      if (selectTrain == TrainPNR[i]) {
        setPerPersonPrice(price[i]);
        break;
      }
    }
  }

public:
  void hyderabad() {
    cout << "\n Trains available for Hyderabad:";
    cout << "\n  " << TrainPNR[18] << "-Train (time: 7:30am) " << price[18]
         << "/- per person";
    cout << "\n  " << TrainPNR[19] << "-Train (time: 2:00pm) " << price[19]
         << "/- per person";
    cout << "\n  " << TrainPNR[20] << "-Train (time: 6:00pm) " << price[20]
         << "/- per person";

    cout << "\n\nChoose your Train: ";
    cin >> selectTrain;

    for (int i = 18; i <= 20; i++) {
      if (selectTrain == TrainPNR[i]) {
        setPerPersonPrice(price[i]);
        break;
      }
    }
  }

public:
  void guwahati() {
    cout << "\n Trains available for Guwahati:";
    cout << "\n  " << TrainPNR[21] << "-Train (time: 12:00am) "
         << price[21] << "/- per person";
    cout << "\n  " << TrainPNR[22] << "-Train (time: 7:40pm) " << price[22]
         << "/- per person";
    cout << "\n  " << TrainPNR[23] << "-Train (time: 10:15pm) "
         << price[23] << "/- per person";

    cout << "\n\nChoose your Train: ";
    cin >> selectTrain;

    for (int i = 21; i <= 23; i++) {
      if (selectTrain == TrainPNR[i]) {
        setPerPersonPrice(price[i]);
        break;
      }
    }
  }

public:
  void pune() {
    cout << "\n Trains available for Pune:";
    cout << "\n  " << TrainPNR[24] << "-Train (time: 1:00am) " << price[24]
         << "/- per person";
    cout << "\n  " << TrainPNR[25] << "-Train (time: 6:45pm) " << price[25]
         << "/- per person";
    cout << "\n  " << TrainPNR[26] << "-Train (time: 11:15pm) "
         << price[26] << "/- per person";

    cout << "\n\nChoose your Train: ";
    cin >> selectTrain;

    for (int i = 24; i <= 26; i++) {
      if (selectTrain == TrainPNR[i]) {
        setPerPersonPrice(price[i]);
        break;
      }
    }
  }

public:
  void amritsar() {
    cout << "\n Trains available for Amritsar :";
    cout << "\n  " << TrainPNR[27] << "-Train (time: 1:11am) " << price[27]
         << "/- per person";
    cout << "\n  " << TrainPNR[28] << "-Train (time: 8:45pm) " << price[28]
         << "/- per person";
    cout << "\n  " << TrainPNR[29] << "-Train (time: 11:15pm) "
         << price[29] << "/- per person";

    cout << "\n\nChoose your Train: ";
    cin >> selectTrain;

    for (int i = 27; i <= 29; i++) {
      if (selectTrain == TrainPNR[i]) {
        setPerPersonPrice(price[i]);
        break;
      }
    }
  }

public:
  void goa() {
    cout << "\n Trains available for Goa:";
    cout << "\n  " << TrainPNR[30] << "-Train (time: 2:00am) " << price[30]
         << "/- per person";
    cout << "\n  " << TrainPNR[31] << "-Train (time: 4:44pm) " << price[31]
         << "/- per person";
    cout << "\n  " << TrainPNR[32] << "-Train (time: 12:15pm) "
         << price[32] << "/- per person";

    cout << "\n\nChoose your Train: ";
    cin >> selectTrain;

    for (int i = 30; i <= 32; i++) {
      if (selectTrain == TrainPNR[i]) {
        setPerPersonPrice(price[i]);
        break;
      }
    }
  }

public:
  void patna() {
    cout << "\n Trains available for Patna:";
    cout << "\n  " << TrainPNR[33] << "-Train (time: 12:00am) "
         << price[33] << "/- per person";
    cout << "\n  " << TrainPNR[34] << "-Train (time: 7:40pm) " << price[34]
         << "/- per person";
    cout << "\n  " << TrainPNR[35] << "-Train (time: 10:15pm) "
         << price[35] << "/- per person";

    cout << "\n\nChoose your Train: ";
    cin >> selectTrain;

    for (int i = 33; i <= 35; i++) {
      if (selectTrain == TrainPNR[i]) {
        setPerPersonPrice(price[i]);
        break;
      }
    }
  }

public:
  void chandigarh() {
    cout << "\n Trains available for Chandigarh:";
    cout << "\n  " << TrainPNR[36] << "-Train (time: 12:00am) "
         << price[36] << "/- per person";
    cout << "\n  " << TrainPNR[37] << "-Train (time: 6:15pm) " << price[37]
         << "/- per person";
    cout << "\n  " << TrainPNR[38] << "-Train (time: 8:15pm) " << price[38]
         << "/- per person";

    cout << "\n\nChoose your Train: ";
    cin >> selectTrain;

    for (int i = 36; i <= 38; i++) {
      if (selectTrain == TrainPNR[i]) {
        setPerPersonPrice(price[i]);
        break;
      }
    }
  }

public:
  void shimla() {
    cout << "\n Trains available for Shimla:";
    cout << "\n  " << TrainPNR[39] << "-Train (time: 10:00am) "
         << price[39] << "/- per person";
    cout << "\n  " << TrainPNR[40] << "-Train (time: 11:45am) "
         << price[40] << "/- per person";
    cout << "\n  " << TrainPNR[41] << "-Train (time: 7:15pm) " << price[41]
         << "/- per person";

    cout << "\n\nChoose your Train: ";
    cin >> selectTrain;

    for (int i = 39; i <= 41; i++) {
      if (selectTrain == TrainPNR[i]) {
        setPerPersonPrice(price[i]);
        break;
      }
    }
  }

public:
  void ayodhya() {
    cout << "\n Trains available for Ayodhya:";
    cout << "\n  " << TrainPNR[42] << "-Train (time: 7:00am) " << price[42]
         << "/- per person";
    cout << "\n  " << TrainPNR[43] << "-Train (time: 11:45am) "
         << price[43] << "/- per person";
    cout << "\n  " << TrainPNR[44] << "-Train (time: 2:15pm) " << price[44]
         << "/- per person";

    cout << "\n\nChoose your Train: ";
    cin >> selectTrain;

    for (int i = 42; i <= 44; i++) {
      if (selectTrain == TrainPNR[i]) {
        setPerPersonPrice(price[i]);
        break;
      }
    }
  }

public:
  void lucknow() {
    cout << "\n Trains available for Lucknow:";
    cout << "\n  " << TrainPNR[45] << "-Train (time: 6:00am) " << price[45]
         << "/- per person";
    cout << "\n  " << TrainPNR[46] << "-Train (time: 9:45pm) " << price[46]
         << "/- per person";
    cout << "\n  " << TrainPNR[47] << "-Train (time: 11:15pm) "
         << price[47] << "/- per person";

    cout << "\n\nChoose your Train: ";
    cin >> selectTrain;

    for (int i = 45; i <= 47; i++) {
      if (selectTrain == TrainPNR[i]) {
        setPerPersonPrice(price[i]);
        break;
      }
    }
  }

public:
  void jaipur() {
    cout << "\n Trains available for Jaipur:";
    cout << "\n  " << TrainPNR[48] << "-Train (time: 2:30am) " << price[48]
         << "/- per person";
    cout << "\n  " << TrainPNR[49] << "-Train (time: 10:45pm) "
         << price[49] << "/- per person";
    cout << "\n  " << TrainPNR[50] << "-Train (time: 11:30pm) "
         << price[50] << "/- per person";

    cout << "\n\nChoose your Train: ";
    cin >> selectTrain;

    for (int i = 48; i <= 50; i++) {
      if (selectTrain == TrainPNR[i]) {
        setPerPersonPrice(price[i]);
        break;
      }
    }
  }
  // Set Price of per person

  void setPerPersonPrice(int price) { perPersonPrice = price; }

  // Get Price of per person

  int getperPersonPrice() { return perPersonPrice; }

  // Get selected Train by passenger

  int getSelectTrain() { return selectTrain; }
};

// Class Node saving user information

class Node {
public:
  string name = "", date = "", departureCity = "", destinationCity = "",
         gender = "", ID = "";
  int age = 0, bookingCode = 0, ticketPNRNo = 0;
  float fare = 0;
  Node *next = NULL;
};

// Class for the main process of booking tickets

class bookingProcedureOfTicket {

private:
  Node *head = NULL;
  Node *current = NULL;
  Node *front = NULL;
  Node *rear = NULL;
  int Bcode = 0;
  int Bcode2 = 0;
  TrainDetails call;

public:
  int Age = 0;
  int members = 0;
  int count = 0;
  float sum = 0;
  float fare = 0;
  float discount = 0;
  float discountFare = 0;
  float totalFare = 0;
  string ID = "";
  int numberOfBooking = 0;

public:
  // bookingProcedureOfTicket() // Constructor
  //{
  //	head = NULL;
  //	front = NULL;
  //	rear = NULL;
  //	count = 0;
  //	sum = 0;
  //	fare = 0;
  //	discount = 0;
  //	discountFare = 0;
  //	totalFare = 0;
  //	numberOfBooking = 0;
  // }

  bool isValidCity(string city) {
    if (toLower(city) == "delhi" || toLower(city) == "mumbai" ||
        toLower(city) == "bangalore" || toLower(city) == "kolkata" ||
        toLower(city) == "chennai" || toLower(city) == "ahmedabad" ||
        toLower(city) == "guwahati" || toLower(city) == "hyderabad" ||
        toLower(city) == "pune" || toLower(city) == "amritsar" ||
        toLower(city) == "chandigarh" || toLower(city) == "shimla" ||
        toLower(city) == "patna" || toLower(city) == "goa" ||
        toLower(city) == "ayodhya" || toLower(city) == "lucknow" ||
        toLower(city) == "jaipur") {
      return true;
    }
    return false;
  }

  // This method will contain all the passenger info
  void inputPassengersInfo() {
    Bcode = rand();
    Bcode2 = 8971 + Bcode;

    string departureCity = "", destinationCity = "", date = "";
    int change = 1;

    do {
      if (change == 1 || change == 2) {
        do {
          cout << "DEPARTURE\n";
          cout << "    The Trains are only available from : "
                  "\nBangalore\tDelhi\t "
                  "Guwahati\tHyderabad\tAhmedabad\tChennai\t\tMumbai\t"
                  "Kolkata\tShimla\tAyodhya\t\tPune\tPatna\t\tGoa\tAmritsar\tCh"
                  "andigarh\tLucknow\t\tJaipur\t\n";
          cout << "\nEnter your departure city from above mentioned cities: ";
          cin >> departureCity;
        } while (!isValidCity(departureCity));
      }

      if (change == 1 || change == 3) {
        do {
          cout << "DESTINATION\n";
          cout << "    The Trains are only available from : "
                  "\nBangalore\tDelhi\t "
                  "Guwahati\tHyderabad\tAhmedabad\tChennai\t\tMumbai\t"
                  "Kolkata\tShimla\tAyodhya\t\tPune\tPatna\tGoa\t\tAmritsar\t"
                  "Chandigarh\tLucknow\tJaipur\t\n";
          cout << "\nEnter your destination city from above mentioned cities: ";
          cin >> destinationCity;
        } while (!isValidCity(destinationCity));
      }

      if (toLower(departureCity) == toLower(destinationCity)) {
        cout << "\nDeparture and Destination cities cannot be same." << endl;
        cout << "\nTo change both Enter 1.\nTo change Deaprture Enter 2.\nTo "
                "Change Destnation Enter 3.\n"
             << endl;
        cout << "Select: ";
        cin >> change;
      }
    } while (toLower(departureCity) == toLower(destinationCity));

    // Date Input
    int d = 0, m = 0, y = 0;
    bool validDate = false;

    do {
      cout << "\nEnter Date: ";
      cin >> d;
      cout << "Enter Month: ";
      cin >> m;
      cout << "Enter Year: ";
      cin >> y;

      validDate = isValidDate(d, m, y);

      if (!validDate) {
        cout << "\nPlease enter a valid date, month and year. You can book "
                "seats upto 30 days in advance.\n";
      }

    } while (!validDate);

    date = to_string(d) + "/" + to_string(m) + "/" + to_string(y);

    cout << "\nFor how many people you want to book tickets: ";
    cin >> members;

    cout << endl;

    numberOfBooking = count + members;

    for (int i = 1; i <= members; i++) {
      Node *passenger_newnode = new Node();

      cout << "Enter passenger name: ";
      cin >> passenger_newnode->name;

      cout << "Enter your age: ";
      cin >> passenger_newnode->age;

      passenger_newnode->date = date;

      cout << "Enter gender: ";
      cin >> passenger_newnode->gender;

      // ID  validation
      cout << "Enter ID : ";
      cin >> ID;

      if (ID.length() != 12) {
        cout << "Enter correct ID number: ";
        cin >> ID;
      }
      passenger_newnode->ID = ID;

      cout << "Your ticket PNR No. is: S-" << i;
      passenger_newnode->ticketPNRNo = i;
      cout << "\n----------------------------------------------------\n"
           << endl;

      passenger_newnode->departureCity = departureCity;
      passenger_newnode->destinationCity = destinationCity;

      passenger_newnode->bookingCode = Bcode2;

      count++; // incrementing number of bookings

      if (numberOfBooking > 5) {
        if (front == NULL) {
          front = passenger_newnode;
          rear = passenger_newnode;
        }

        else {
          rear->next = passenger_newnode;
          rear = passenger_newnode;
        }
      }

      else {
        if (head == NULL) {
          head = passenger_newnode;
          passenger_newnode->next = NULL;
        }

        else {
          current = head;

          while (current->next != NULL) {
            current = current->next;
          }

          current->next = passenger_newnode;
        }
      }
    }

    // Check if user has entered correct destinationCity according to available
    // Trains

    if (destinationCity == "Delhi" || destinationCity == "delhi") {
      call.delhi();
    } else if (destinationCity == "Mumbai" || destinationCity == "mumbai") {
      call.mumbai();
    } else if (destinationCity == "Bangalore" ||
               destinationCity == "bangalore") {
      call.bangalore();
    } else if (destinationCity == "Chennai" || destinationCity == "chennai") {
      call.chennai();
    } else if (destinationCity == "Kolkata" || destinationCity == "kolkata") {
      call.kolkata();
    } else if (destinationCity == "Chennai" || destinationCity == "chennai") {
      call.chennai();
    } else if (destinationCity == "Guwahati" || destinationCity == "guwahati") {
      call.guwahati();
    } else if (destinationCity == "Hyderabad" ||
               destinationCity == "hyderabad") {
      call.hyderabad();
    } else if (destinationCity == "Ahmedabad" ||
               destinationCity == "ahmedabad") {
      call.ahmedabad();
    } else if (destinationCity == "Amritsar" || destinationCity == "amritsar") {
      call.amritsar();
    } else if (destinationCity == "Chandigarh" ||
               destinationCity == "chandigarh") {
      call.chandigarh();
    } else if (destinationCity == "Shimla" || destinationCity == "shimla") {
      call.shimla();
    } else if (destinationCity == "Pune" || destinationCity == "pune") {
      call.pune();
    } else if (destinationCity == "Patna" || destinationCity == "patna") {
      call.patna();
    } else if (destinationCity == "Goa" || destinationCity == "goa") {
      call.goa();
    } else if (destinationCity == "Ayodhya" || destinationCity == "ayodhya") {
      call.ayodhya();
    } else if (destinationCity == "Lucknow" || destinationCity == "lucknow") {
      call.lucknow();
    } else if (destinationCity == "Jaipur" || destinationCity == "jaipur") {
      call.jaipur();
    } else {
      cout << "Wrong destinationCity\n";
    }

    // Conditions for printing message
    if (numberOfBooking > 5) {
      cout << "\nYour booking code is " << Bcode2;
      cout << "\nNo more seats are availbale, you are added in the waiting list"
           << endl;
    } else {
      cout << "\nYour booking code is " << Bcode2;
      cout << "\nTo proceed and view total price, Press 2.";
    }
  }

  // Display Queue

  void showWaitingList() {
    current = front;

    if (current == NULL)
      cout << "Waiting list is empty" << endl;

    else {
      while (current != NULL) {
        cout << "______________________________________________________________"
                "_______ "
             << endl
             << endl;
        cout << "| PNR No.:     \t"
             << "S-" << current->ticketPNRNo << " \t\t\t|" << endl;
        cout << "| Passenger Name: \t" << current->name << " \t\t\t|" << endl;
        cout << "| Age:            \t" << current->age << " \t\t\t|" << endl;
        cout << "| ID:           \t" << current->ID << " \t|" << endl;
        cout << "| Booking Date:   \t" << current->date << " \t\t|" << endl;
        cout << "| From:           \t" << current->departureCity << " \t\t|"
             << endl;
        cout << "| To:             \t" << current->destinationCity << " \t\t|"
             << endl;
        cout << "______________________________________________________________"
                "_______ "
             << endl
             << endl;

        current = current->next;
      }
    }
  }

  // To calculate Total Price of tickets

  void calculatePrice() {
    current = head;
    bool found = false;
    fare = call.getperPersonPrice();
    totalFare = sum = 0;

    int bcode;

    cout << "Enter your booking code: ";
    cin >> bcode;

    if (current == NULL)
      cout << "\nNo price to display";

    while (current != NULL) {
      if (bcode == current->bookingCode) {
        if (current->age > 0 && current->age <= 6) {
          discount = call.getperPersonPrice() * 0.5; // 50% discount
          discountFare = call.getperPersonPrice() - discount;
          current->fare = discountFare;
          sum += discountFare; // Total fare
        } else if (current->age > 6 && current->age <= 12) {
          discount = call.getperPersonPrice() * 0.3; // 30% discount
          discountFare = call.getperPersonPrice() - discount;
          current->fare = discountFare;
          sum += discountFare; // Total fare
        } else if (current->age >= 60) {
          discount = call.getperPersonPrice() * 0.2; // 20% discount
          discountFare = call.getperPersonPrice() - discount;
          current->fare = discountFare;
          sum += discountFare; // Total fare
        } else {
          fare = call.getperPersonPrice();
          current->fare = fare;
          sum += fare;
        }

        found = true;
      }
      current = current->next;
    }

    if (found == false) {
      cout << "Enter correct booking code" << endl;
    } else {
      totalFare = sum;
      cout << "Your Total Fare is: " << totalFare;
    }
  }

  // This will display the information of all the bookings

  void viewInfo() {
    cout << endl;

    current = head;
    int bookCode;
    bool found = false;

    cout << "Enter ticket code: ";
    cin >> bookCode;

    if (current == NULL) {
      cout << "There is no booking to display." << endl;
    }

    while (current != NULL) {
      if (bookCode == current->bookingCode) {
        cout << "______________________________________________________________"
                "_______ "
             << endl
             << endl;
        cout << "| PNR No.:     \t"
             << "S-" << current->ticketPNRNo << " \t\t\t|" << endl;
        cout << "| Passenger Name: \t" << current->name << " \t\t\t|" << endl;
        cout << "| Age:            \t" << current->age << " \t\t\t|" << endl;
        cout << "| ID:           \t" << current->ID << " \t|" << endl;
        cout << "| Booking Date:   \t" << current->date << " \t\t|" << endl;
        cout << "| From:           \t" << current->departureCity << " \t\t|"
             << endl;
        cout << "| To:             \t" << current->destinationCity << " \t\t|"
             << endl;
        cout << "| Train No.:     \tShatabdi Express-" << call.getSelectTrain() << " \t\t|"
             << endl;
        cout << "| Fare:           \t" << current->fare << " \t\t\t|" << endl;
        cout << "______________________________________________________________"
                "_______ "
             << endl;
        cout << endl;
        found = true;
      }
      current = current->next;
    }
    if (found != true) {
      cout << "Booking not found" << endl;
    }
  }

  // Modify any user Ticket incase of incorrect information

  void modifyTicket() {
    int bcode;
    int PNR;
    int found = -1;

    cout << "Enter your booking code: ";
    cin >> bcode;

    cout << "\nEnter PNR number to edit: S-";
    cin >> PNR;

    current = head;
    while (current != NULL) {
      if (bcode == current->bookingCode && PNR == current->ticketPNRNo) {
        cout << "Enter passenger name: ";
        cin >> current->name;

        cout << "Enter your age: ";
        cin >> current->age;

        cout << "Enter date: ";
        cin >> current->date;

        cout << "Enter gender: ";
        cin >> current->gender;

        found = 0;
        cout << endl;
        break;
      }
      current = current->next;
    }

    if (found == -1) {
      cout << "Record not Found" << endl;
    }
  }

  // Method to confirm payment after booking

  void confirmPayment() {
    current = head;

    int bcode, userInput;
    string ID;
    bool found = false;

    cout << "Enter your booking code: ";
    cin >> bcode;

    cout << "\nEnter ID number of booking of 1st person: ";
    cin >> ID;

    if (current == NULL) {
      cout << "\nThere is no booking aganist entered booking code" << endl;
    }

    while (current != NULL) {
      if (bcode == current->bookingCode && ID == current->ID) {
        found = true;
        break;
      }
      current = current->next;
    }

    if (found) {

      cout << "\nYour Total Fare is: " << totalFare << endl;

      cout << "\nPay fare amount to confirm ticket: ";
      cin >> userInput;

      if (userInput == totalFare) {
        cout << "\nYour booking is confirmed, enjoy your trip!!!";
      } else {
        cout << "\nPlease pay the required amount" << endl;

        cout << "\nPay fare amount to confirm ticket: ";
        cin >> userInput;

        if (userInput == totalFare) {
          cout << "\nYour booking is confirmed, enjoy your trip!!!";
        }

        else {
          cout << "\nYour Booking is cancelled, book again." << endl;
        }
      }
    } else {
      cout << "\nBookings not found, book your ticket first" << endl;
    }
  }

  // To clear all passenger data from the system

  void DeletingPassengerInfo() {
    current = head;
    int Bcode;
    // char decide;
    bool found = false;

    cout << "Enter your booking code to cancel booking: ";
    cin >> Bcode;

    if (head == NULL) {
      cout << "No booking to cancel" << endl;
    } else {
      if (current->next ==
          NULL) // If only one Node in Linked List this condition will execute
      {
        if (Bcode == current->bookingCode) {
          head = NULL;
          delete (current);
          found = true;
        }
      } else {
        // If there are more than one node and first node is deleting
        if (current == head && Bcode == current->bookingCode) {
          Node *temp = current;
          current = current->next;
          delete (temp);
          found = true;
        } else // If deleting node from end or middle
        {
          Node *previous = current;
          while (current != NULL) {
            if (Bcode == current->bookingCode) {
              previous->next = current->next;
              delete (current);
              found = true;
            }

            current = current->next;
          }

          //					numberOfBooking--;

          // Add node from queue to Linked List

          //					if(numberOfBooking<2)
          //					{
          //						Node* transfer = new
          // Node(); 						transfer =
          // front; front = front->next;
          //
          //
          //					    current = head;
          //
          //					   while(current->next != NULL)
          //					   {
          //						current = current->next;
          //					   }
          //
          //					   current->next = transfer;
          //					   delete(transfer);
          //					}
        }
      }

      if (found == false) {
        cout << "\nBooking not found" << endl;
      } else {
        cout << "\nBooking is cancelled, successfully" << endl;
      }
    }
  }
};

// Menu which will select our desirable query

class Menu {
  int choice = 0;
  bookingProcedureOfTicket call;

public:
  void showMenu() {

    do {
      cout << endl;
      cout << "\n----------------------------------" << endl;
      cout << "  Indian Railways ";
      cout << "\n";
      cout << "----------------------------------";
      cout << "\n Connecting thousands miles everyday..!!";
      cout << "\n 17 Services for the Cities and many more to come.....";
      cout << "\n Press 17 to see servicable cities";
      cout << "\n 1 Booking";
      cout << "\n 2 Price";
      cout << "\n 3 View Ticket details";
      cout << "\n 4 Modify Ticket details";
      cout << "\n 5 Payment confirmation ";
      cout << "\n 6 Cancel your booking";
      cout << "\n 7 Show waiting List";
      cout << "\n 0 Exit \n";
      cout << "\nEnter your Choice:  ";
      cin >> choice;

      switch (choice) {
      case 17:
        cout << endl;
        cout << "\n    Bangalore \n";
        cout << "\n    Mumbai \n";
        cout << "\n    Chennai \n";
        cout << "\n    Kolkata \n";
        cout << "\n    Ahmedabad \n";
        cout << "\n    Hyderabad \n";
        cout << "\n    Guwahati \n";
        cout << "\n    Pune \n";
        cout << "\n    Patna \n";
        cout << "\n    Goa \n";
        cout << "\n    Shimla \n";
        cout << "\n    Chandigarh \n";
        cout << "\n    Amritsar \n";
        cout << "\n    Lucknow \n";
        cout << "\n    Ayodhya \n";
        cout << "\n    Jaipur \n";
        cout << "\n    Delhi \n" << endl;

        break;
      case 1:
        cout << endl;
        cout << "\n    Book our Train Tickets \n" << endl;
        call.inputPassengersInfo();
        break;
      case 2:
        cout << endl;
        call.calculatePrice();
        break;
      case 3:
        cout << endl;
        call.viewInfo();
        break;
      case 4:
        cout << endl;
        call.modifyTicket();
        break;
      case 5:
        cout << endl;
        call.confirmPayment();
        break;
      case 6:
        cout << endl;
        call.DeletingPassengerInfo();
        break;
      case 7:
        cout << endl;
        call.showWaitingList();
      }

    } while (choice != 0);
  }
};

// Main Method

int main() {
  Menu call; // Menu Object

  call.showMenu(); // Called method

  return 0;
}

// time_t t = time(NULL);
// tm* timePtr = localtime(&t);
//
// cout << "seconds= " << timePtr->tm_sec << endl;
// cout << "minutes = " << timePtr->tm_min << endl;
// cout << "hours = " << timePtr->tm_hour << endl;
// cout << "day of month = " << timePtr->tm_mday << endl;
// cout << "month of year = " << timePtr->tm_mon + 1 << endl;
// cout << "year = " << timePtr->tm_year + 1900 << endl;
// cout << "weekday = " << timePtr->tm_wday << endl;
// cout << "day of year = " << timePtr->tm_yday << endl;
// cout << "daylight savings = " << timePtr->tm_isdst << endl;

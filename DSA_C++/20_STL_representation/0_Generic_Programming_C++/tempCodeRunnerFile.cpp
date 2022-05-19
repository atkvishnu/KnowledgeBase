Book b1("C++", 100);            // old edition book
    Book b2("python", 120);
    Book b3("java", 130);

    list<Book> l;

    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);

    Book booktofind("C++", 110);      // new edition book

    BookCompare cmp;
    auto it = search3(l.begin(), l.end(), booktofind,  cmp);         // in place of auto we can have list<Book>::iterator
    if(it != l.end()){
        cout << "Book found in the library" << endl;
    } else {
        cout << "Not found"<< endl;
    }
#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();



    // ---- Part 2: your Uno scene goes below ----

    std::cout << "== My Scene =="<< std::endl;
    std::unique_ptr<List<Player>> players = makeList<Player>();
    players->addFront(new Player(1, "Bob"));
    players->addFront(new Player(2, "Mike"));
    players->addFront(new Player(3, "Josh"));
    players->addFront(new Player(4, "Carl"));
    std::cout << "Game Started With Players: "<< std::endl;
    players->print();
    std::cout << "Billy Joins Mid-Round!: "<< std::endl;
    players->addAnywhere(2, new Player(5, "Billy"));
    players->print();
    std::cout << "Carl Plays a Reverse Card!: "<< std::endl;
    players->reverse();
    players->print();
    std::cout << "Mike Runs Out of Cards!: "<< std::endl;
    players->deleteAnywhere(1);
    players->print();
    std::cout << "Our Game Now: "<< std::endl;
    players->print();
    std::cout << "Annother Game in The Room!: "<< std::endl;
    std::unique_ptr<List<Player>> players2 = makeList<Player>();
    players2->addFront(new Player(6, "Ringo"));
    players2->addFront(new Player(7, "Paul"));
    players2->addFront(new Player(8, "Geroge"));
    players2->addFront(new Player(9, "James"));
    players2->print();
    std::cout << "Both Games Merge!: "<< std::endl;
    players->concat(players2.get());
    std::cout << "Our Game Now: "<< std::endl;
    players->print();
    std::cout << "Old Game Now: "<< std::endl;
    players2->print();
}

1. Why does concat only need to work between two lists of the same representation? What would you have to do differently, or what would go wrong, if you tried to make it work between a LinkedList and an ArrayList?
   Since we access and iterate through the different types of lists differently we would certainly encounter errors when we try to access the array or next pointers that don't exist in the opposite list type. To make
   it work we would need special handling for adding an array list to a linked list and a vise-versa.

2. Walk through reverse() on your linked list: name the three pointers you need alive at once, and explain why losing track of any one of them mid-loop corrupts the list.
   current_node is the current node. I use previous_node to keep track of the node before current since we can't iterate backwards through the list. next_node is the current node's next value. Because reverse is
   effectively swapping the pointer's directions, losing these temporarily stored values at any point in the loop causes us to overwrite necessary information with no access to the old value.

3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for position in each, and what does your implementation do if a caller passes a position outside it?
   for addAnywhere we can add between [0 and size_]. for deleteAnywhere the bounds are [0, size-1] Since our array is indexed to 0 and size is the number of elements, size is always the index after our current value so 
    we can add up to that or remove up to the one before it. For both my implementation prints something like
   "Invalid addAnywhere Array Index."

4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront and deleteFront never needed to? What would change about concat’s performance if 
   If LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere if you added one back?
   A tail pointer would allow concat to just set the tail's next tot the new lists's head and then we update tail and size and where done. Without it we have to climb all the way to the tail so we can start adding to
   the end of the list. addFront and deleteFront don't have to because we just update our head pointer and only interact with the top element. With a tail we could go form O(n) to O(1)

5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what has to shift and in which direction, and why shifting in the wrong direction would overwrite data you still need.
   addAnywhere will need to shift all data after the index by 1 towards the back to open up a "slot" for our new value to go in. If we shift forwards we would actually be deleting from the given index (with a memory leak as we don't clear the overwritten pointer)

6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of play, and explain what would visibly break in the game if that call were missing.
   at line 46 I call reverse and it would break the game because Carl plays a reverse and so if we dont reverse our list our order of players will be incorrect. 


gi
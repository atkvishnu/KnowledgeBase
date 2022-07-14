import java.util.*;
import java.io.*;


class LL_intersection {


	static Node head1, head2;

	static class Node {
		int data;
		Node next;

		Node(int d) {
			data = d;
			next = null;
		}
	}

	int getCount(Node node) {
		Node curr = node;
		int counter = 0;
		while(curr != null) {
			counter++;
			curr = curr.next;
		}
		return counter;
	}


	int the_longer_one() {
		int c1 = 0; 
		int c2 = 0;
		int diff;
		c1 = getCount(head1);
		c2 = getCount(head2);
		if(c1 > c2) {
			diff = c1 - c2;
			return _getIntersection(diff, head1, head2);
		} else {
			diff = c2 - c1;
			return _getIntersection(diff, head2, head1);
		}
	}


	int _getIntersection(int d, Node node1, Node node2) {
		Node curr1 = node1;
		Node curr2 = node2;
		for(int i = 0; i < d; i++) {
			if(curr1 == null) {
				return -1;
			}
			curr1 = curr1.next;
		}
		while(curr1 != null && curr2 != null) {
			if(curr1.data == curr2.data) {
				return curr1.data;
			} 	
			curr1 = curr1.next;
			curr2 = curr2.next;
		}
		return -1;
	}


	public static void main(String[] args) {
		LL_intersection linked_list = new LL_intersection();

		// creating first linked list
        linked_list.head1 = new Node(3);
        linked_list.head1.next = new Node(6);
        linked_list.head1.next.next = new Node(9);
        linked_list.head1.next.next.next = new Node(15);
        linked_list.head1.next.next.next.next = new Node(30);
 
        // creating second linked list
        linked_list.head2 = new Node(10);
        linked_list.head2.next = new Node(15);
        linked_list.head2.next.next = new Node(30);
        
		System.out.println(linked_list.the_longer_one());

	}















}
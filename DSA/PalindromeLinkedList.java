import java.util.*;
import java.lang.*;
import java.io.*;

public class ListNode {
	int val;
	ListNode next;
	ListNode() {}
	ListNode(int val) { this.val = val; }
	ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
   
   public class PalindromeLinkedList {
   
   public static boolean isPalindrome(ListNode head) {
       ListNode fast = head, slow = head;
       while (fast != null && fast.next != null) {
	   fast = fast.next.next;
	   slow = slow.next;
       }
       if(fast!= null){
	   slow = slow.next;
       }
       slow = reverse(slow);
       fast= head;
       while (slow!=null){
	   if(fast.val != slow.val){
	       return false;
	   }
	   fast = fast.next;
	   slow = slow.next;
       }
       return true;
}
    
       public static ListNode reverse(ListNode head) {
	   ListNode prev = null;
	   while (head!=null){
	       ListNode next = head.next;
	       head.next = prev;
	       prev = head;
	       head =  next;
	       
	   }
	return prev;
       }
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		ListNode head = new ListNode(12);
		ListNode next = new ListNode(14);
		head.next = next;
		next.next = null;
		System.out.println( isPalindrome(head));
		sc.close();
	}
}

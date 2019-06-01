/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class PrioritySolution {
  public ListNode mergeKLists(ListNode[] lists) {
    if (lists == null) return null;

    PriorityQueue<ListNode> queue = new PriorityQueue<ListNode>(new ListNodeComparator());
    for (int i = 0; i < lists.length; i++) {
      if (lists[i] != null)
        queue.add(lists[i]);
    }

    ListNode head = null;
    ListNode current = null;
    while (!queue.isEmpty()) {
      ListNode n = queue.peek();
      queue.remove();
      if (current != null) current.next = n;
      current = n;
      if (head == null) head = current;
      if (n.next != null) {
        queue.add(n.next);
      }
    }

    return head;
  }
}

class ListNodeComparator implements Comparator<ListNode> {
  public int compare(ListNode a, ListNode b) {
    if (a.val > b.val) return 1;
    else return -1;
  }
}

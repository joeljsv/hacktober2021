// You can modify this class further for your use.

import java.util.Iterator;


/**
 * @author CinematicGenius007 (Ayush)
 * {@summary This is a Doubly Linked List [DS]. }
 */
public class DoublyLinkedList<T> implements Iterable<T> {
	private static class Node<T> {
		T data;
		Node<T> prev, next;
		public Node(T data, Node<T> previous, Node<T> next) {
			this.data = data;
			this.prev = previous;
			this.next = next;
		}
		@Override
		public String toString() {
			return data.toString();
		}
	}
	
	private int len = 0;
	public int length() {return len;}
	
	private Node<T> head = null;
	private Node<T> tail = null;
	
	/**
	 * 
	 * @param t - The generic datatype
	 * @param atFirst - Whether to add at the beginning or not, of the linked list.
	 */
	public void add(T t, boolean atFirst) {
		if (atFirst) 
			addFirst(t);
		else
			addLast(t);
		len++;
	}
	
	public void add(T t) {
		add(t, false);
	}
	
	private void addFirst(T t) {
		if (isEmpty() || head == null) {
			head = tail = new Node<>(t, null, null);
		} else {
			head.prev = new Node<>(t, null, head);
			head = head.prev;
		}
	}
	
	private void addLast(T t) {
		if (isEmpty() || head == null) {
			head = tail = new Node<>(t, null, null);
		} else { 
			tail.next = new Node<>(t, tail, null);
			//Assigning new tail
			tail = tail.next;
		}
	}
	
	@Override
	public String toString() {
		if (len == 0) return "[]";
		String str = "[";
		Node<T> temp = head;
		for (int i = 0; i < len-1; i++) {
			str += temp.data + ", ";
			temp = temp.next;
		}
		str += temp.data + "]";
		return str;
	}
	
	public void clear() {
		Node<T> temp = head;
		while (temp != null) {
			Node<T> next = temp.next;
			temp.prev = temp.next = null;
			temp.data = null;
			temp = next;
		}
		head = tail = temp = null;
		len = 0;
	}
	
	public boolean isEmpty() {return length() == 0;}
	
	public T peekFirst() {
		if (isEmpty()) throw new RuntimeException("Empty list!");
		return head.data;
	}
	
	public T peekLast() {
		if (isEmpty()) throw new RuntimeException("Empty list!");
		return tail.data;
	}

	@Override
	public Iterator<T> iterator() {
		return new Iterator <T> () {
			private Node<T> trav = head;
			@Override public boolean hasNext() {
				return trav != null;
			}
			@Override public T next() {
				T data = trav.data;
				trav = trav.next;
				return data;
			}
			
		};
	}

}

public class Stack {
    int[] A;
    int top;
    int capacity;

    public Stack(int capacity) {
        this.capacity = capacity;
        this.A = new int[capacity];
        this.top = -1;
    }

    public boolean push(int x) {
        if(isFull()) {
            return false;
        }
        A[++top] = x;
        return true;
    }

    public int pop() {
        if(isEmpty()) {
           return Integer.MIN_VALUE; 
        }
        return A[top--];
    }

    private boolean isEmpty() { return top == -1; }

    private boolean isFull() { return top == capacity-1; }

    public static void main(String[] args) {
        Stack stack = new Stack(7);
        stack.push(15);
        stack.push(6);
        stack.push(2);
        stack.push(9);
        stack.push(17);
        stack.push(3);

        System.out.printf("%d\n", stack.pop());
        System.out.printf("%d\n", stack.pop());
        System.out.printf("%d\n", stack.pop());
        System.out.printf("%d\n", stack.pop());
    }
}


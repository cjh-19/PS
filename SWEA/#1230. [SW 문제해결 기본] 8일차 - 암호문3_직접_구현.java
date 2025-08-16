import java.util.*;
import java.io.*;

public class Solution {
    private static int N, NODE_MAX = 5000;
    private static StringBuilder sb = new StringBuilder();
    private static class Node {
        int data; // 암호문
        Node next; // 다음 노드 주소

        public Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public static class LinkedList {
        Node head; // 맨 앞
        Node tail; // 맨 뒤
        Node[] nodePool; // 각 노드의 위치를 저장
        int nodeCount; // 현재 추가된 노드의 개수

        public LinkedList() {
            head = null;
            nodePool = new Node[NODE_MAX];
            nodeCount = 0;
        }

        // 새로운 노드를 생성하고 해당 노드 반환 후 nodeCount 중기
        public Node newNode(int data) {
            nodePool[nodeCount] = new Node(data);
            return nodePool[nodeCount++];
        }

        // index개 이후에 노드들을 추가
        public void insert(int idx, int[] nums) {
            int st = 0;
            // 맨 앞에 노드를 붙이는 경우 -> head 변경
            if(idx==0) {
                if(this.head!=null) {
                    Node node = newNode(nums[0]);
                    node.next = this.head;
                    this.head = node;
                } else {
                    this.head = newNode(nums[0]);
                }
                // 남은 nums를 head 뒤에 차례대로 붙이기
                idx = 1;
                st = 1;
            }

            // 현재 위치
            Node cur = this.head;
            // idx개 만큼 이동
            for(int i=1; i<idx; i++) {
                cur = cur.next;
            }
            // nums 추가
            for(int i=st; i<nums.length; i++) {
                Node node = newNode(nums[i]);
                node.next = cur.next; // cur다음 노드를 node의 다음 노드로 설정
                cur.next = node;
                cur = node;
            }

            // 마지막까지 삽입한 노드의 다음 노드가 null이라면 tail정보를 현재 노드로 설정
            if(cur.next == null) this.tail=cur;
        }

        // idx번 인덱스부터 cnt개 만큼 삭제
        public void delete(int idx, int cnt) {
            Node cur = this.head;

            // head가 삭제되는 경우
            if(idx==0) {
                for(int i=0; i<cnt; i++) {
                    cur = cur.next;
                }
                this.head = cur;
                return;
            }

            // 아니라면 idx개 만큼 이동
            for(int i=1; i<idx; i++) {
                cur = cur.next;
            }

            // 삭제되기 직전 위치
            Node anchor = cur;
            for(int i=0; i<cnt; i++) {
                cur = cur.next;
            }
            // 삭제 직전 노드와 마지막 삭제 노드의 다음 노드를 연결
            anchor.next = cur.next;

            if(anchor.next == null) this.tail = anchor;
        }

        // 맨 뒤에 노드 추가
        public void add(int data) {
            Node cur = this.tail;
            Node node = newNode(data);
            cur.next = node;
            this.tail = node;
        }

        // 가장 앞 10개 노드 출력
        public void print() {
            Node cur = this.head;
            for(int i=0; i<10; i++) {
                sb.append(cur.data).append(" ");
                cur = cur.next;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        for(int t=1; t<=10; t++) {
            N = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            LinkedList list = new LinkedList();
            int[] initArr = new int[N];
            for(int i=0; i<N; i++) {
                initArr[i] = Integer.parseInt(st.nextToken());
            }

            // 초기 암호 리스트 만들기
            list.insert(0, initArr);

            int M = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            for(int i=0; i<M; i++) {
                char cmd = st.nextToken().charAt(0);
                int x, y;
                switch(cmd) {
                    case 'I':
                        x = Integer.parseInt(st.nextToken());
                        y = Integer.parseInt(st.nextToken());
                        int[] tmp = new int[y];
                        for(int j=0; j<y; j++) {
                            tmp[j] = Integer.parseInt(st.nextToken());
                        }
                        list.insert(x, tmp);
                        break;
                    case 'D':
                        x = Integer.parseInt(st.nextToken());
                        y = Integer.parseInt(st.nextToken());
                        list.delete(x, y);
                        break;
                    case 'A':
                        y = Integer.parseInt(st.nextToken());
                        for(int j=0; j<y; j++) {
                            list.add(Integer.parseInt(st.nextToken()));
                        }
                        break;
                }
            }
            sb.append("#").append(t).append(" ");
            list.print();
            sb.append("\n");
        }
        System.out.print(sb);
    }
}
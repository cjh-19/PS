// MinHeap
class PriorityQueue{
    // heap 초기화
    constructor() {
        this.heap = [];
    }

    // 요소를 힙에 추가하고 힙 속성 유지
    enqueue(element){
        this.heap.push(element); // 요소 추가
        this._bubbleUp(); // 힙 속성 유지
    }

    // 가장 우선순위가 높은 요소 제거하고 반환
    dequeue(){
        if(this.size() === 1) return this.heap.pop();
        const top = this.heap[0];
        this.heap[0] = this.heap.pop(); // 힙의 마지막 요소 최상단으로 배
        this._sinkDown(0); // 최상단 요소를 제자리에 놓으며 힙속성 유지
        return top;
    }

    // 힙의 크기 반환
    size(){
        return this.heap.length;
    }

    // 새로 추가된 요소를 올려서 힙 속성 유지
    _bubbleUp() {
        let index = this.heap.length - 1; // 마지막 요소 인덱스 값
        const element = this.heap[index] // 마지막 요소

        while(index > 0) {
            // 부모 노드 인덱스 값 : (자식노드 인덱스 - 1) / 2
            let parentIndex = Math.floor((index - 1) / 2);
            let parent = this.heap[parentIndex];

            // 부모보다 작거나 같은 경우 힙속성 유지됨
            // 프로그램의 첫번째 요소 - 점수가 부모노드보다 큰 경우 힙속성 유지
            // 점수가 같고 호출시간이 부모노드보다 크거나 같으면 힙속성 유지
            if(element[0] > parent[0] || (element[0] === parent[0] && element[1] >= parent[1])) break;

            this.heap[index] = parent; // 부모 노드를 자식 노드로 내림
            index = parentIndex;
        }
        this.heap[index] = element; // 부모노드 위치에 추가할 노드로 교환
    }

    // 루트에서 제거된 요소를 내려보내서 힙 속성 유지
    _sinkDown(index) {
        const length = this.size();
        const element = this.heap[index]; // 최상단 노드

        while(true) {
            let leftChildIndex = 2 * index + 1; // 왼쪽 자식노드 인덱스
            let rightChildIndex = 2 * index + 2; // 오른쪽 자식노드 인덱스
            let leftChild, rightChild;
            let swap = null; // element와 교환할 자식 노드의 인덱스

            // 왼쪽 자식 노드가 있는 경우
            if (leftChildIndex < length) {
                leftChild = this.heap[leftChildIndex];
                // 왼쪽 자식노드가 우선순위가 더 높다면 힙 속성 유지 x
                if(leftChild[0] < element[0] || (leftChild[0] === element[0] && leftChild[1] < element[1])) {
                    swap = leftChildIndex;
                }
            }

            // 오른쪽 자식노드가 있는 경우
            if(rightChildIndex < length){
                rightChild = this.heap[rightChildIndex];
                if(
                    (swap === null && (rightChild[0] < element[0] || (rightChild[0] === element[0] && rightChild[1] < element[1]))) ||
                    (swap != null && (rightChild[0] < leftChild[0] || (rightChild[0] === leftChild[0] && rightChild[1] < leftChild[1])))
                ) {
                    swap = rightChildIndex;
                }
            }

            if(swap === null) break; // 힙속성이 유지되있다면 종료

            this.heap[index] = this.heap[swap]; // 추가한 노드 위치에 자식노드를 올리고
            index = swap; // 자식 노드 인덱스를 저장
        }

        this.heap[index] = element; // 맨 마지막 교환 위치에 추가한 노드 값 저장
    }
}

function solution(program) {
    // 프로그램을 호출시간 기준으로 정렬
    program.sort((a,b) => a[1] - b[1]);
    // pq에는 1. 점수 2. 호출 순으로 우선순위가 매겨짐
    const pq = new PriorityQueue(); // 대기 프로그램을 담을 큐
    const answer = new Array(11).fill(0); // 각 우선순위별 대기 시간 저장
    let currentTime = 0; // 현재 시간 저장
    let index = 0; // 프로그램 인덱스

    // 프로그램을 모두 확인했고, pq가 비어있다면 종료
    while(index < program.length || pq.size() > 0){
        // 현재 시간까지 호출된 모든 프로그램을 대기 큐에 추가
        while(index < program.length && program[index][1] <= currentTime){
            pq.enqueue(program[index]); // 호출시간으로 정렬 -> 호출이 빠른 순서대로 추가
            index++;
        }
        
        // pq에 대기 프로그램이 있을 경우
        if(pq.size() > 0) {
            // 가장 높은 우선순위의 프로그램을 꺼내 실행
            const [score, callTime, duration] = pq.dequeue();
            answer[score] += currentTime - callTime; // 대기시간 계산하여 추가
            currentTime += duration // 현재시간 업데이트
        }
        else if(index < program.length) {
            // 큐가 비어있으면 다음 프로그램의 호출 시간으로 현재 시간 설
            currentTime = program[index][1];
        }
    }

    answer[0] = currentTime; // 총 실행시

    return answer;
}
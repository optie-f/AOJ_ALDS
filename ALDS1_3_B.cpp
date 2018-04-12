#include <iostream>
#define INT_MAX 2147483647

struct Process{
  std::string name;
  int time;
};

class Queue {
private:
  Process Table[100005];
  int head;
  int top;
public:
  Queue(){ head=0; top=0; };
  void Enqueue(Process P);
  Process Dequeue();
  bool isEmpty(){ return head==top; };
  void show();
};

void Queue::show(){
  std::cout << "head : " << head << '\n';
  std::cout << "top : " << top  << '\n';
};

void Queue::Enqueue(Process P){
  Table[top] = P;
  top = (top+1)%100005;
};

Process Queue::Dequeue(){
  Process p = Table[head];
  head = (head+1)%100005;
  return p;
};

int main(int argc, char const *argv[]) {
  int n;
  int q;
  int cumtime=0;
  Process P;
  Queue queue = Queue();
  std::cin >> n >> q;

  for (size_t i = 0; i < n; i++) {
    std::cin >> P.name;
    std::cin >> P.time;
    queue.Enqueue(P);
  }

  while (!queue.isEmpty()) {
    P = queue.Dequeue();
    P.time -= q;
    if (P.time>0) {
      queue.Enqueue(P);
      cumtime += q;
    } else {
      cumtime += (q + P.time);
      std::cout << P.name << ' ' << cumtime << '\n';
    }
  }

  return 0;
}

#include <iostream>
#include "tbb/task_group.h"
#include "tbb/tbb.h"
#include <Magick++.h>

using namespace tbb;

int Fib(int n) {
    if (n < 2) {
        return n;
    } else {
        int x, y;
        task_group g;
        g.run([&] { x = Fib(n - 1); }); // spawn a task
        g.run([&] { y = Fib(n - 2); }); // spawn another task
        g.wait();                // wait for both tasks to complete
        return x + y;
    }
}


using namespace std;
using namespace tbb::flow;

//graph g;
//continue_node<continue_msg> hello(
//        g,
//        [](const continue_msg &) {
//            cout << "Hello";
//        }
//);
//continue_node<continue_msg> world(
//        g,
//        [](const continue_msg &) {
//            cout << " World\n";
//        }
//);
//make_edge(hello, world);
//hello.try_put(continue_msg());
//g.wait_for_all();
//return 0;

int main() {
    auto image = new Magick::Image();
    image->read("/home/kodoo/Pictures/image002.jpg");
    image->write("/home/kodoo/Pictures/image002_2.jpg");
}
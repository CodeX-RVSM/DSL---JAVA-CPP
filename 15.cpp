#include <iostream>
using namespace std;

struct Patient
{
    string name;
    int priority;
};

class PriorityQueue
{
private:
    Patient arr[100];
    int rear;

public:
    PriorityQueue()
    {
        rear = -1;
    }

    bool isEmpty()
    {
        return (rear == -1);
    }

    bool isFull()
    {
        return (rear == 99);
    }

    void enqueue(Patient p)
    {
        if (isFull())
        {
            cout << "Queue Overflow\n";
            return;
        }
        int i;
        for (i = rear; i >= 0; i--)
        {
            if (arr[i].priority > p.priority || (arr[i].priority == p.priority && i == 0))
            {
                break;
            }
            arr[i + 1] = arr[i];
        }
        arr[i + 1] = p;
        rear++;
    }
    Patient dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return {"", -1};
        }
        Patient frontPatient = arr[rear];
        rear--;
        return frontPatient;
    }
};

int main()
{
    PriorityQueue pq;
    int n;
    cout << "Enter the number of patients: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Patient p;
        cout << "Enter patient " << i + 1 << " name: ";
        cin >> p.name;
        cout << "Enter priority (1 for Serious, 2 for Non-serious, 3 for General Check-Up): ";
        cin >> p.priority;
        pq.enqueue(p);
    }
    cout << "Serving patients:\n";
    Patient patients[100];
    int index = 0;
    while (!pq.isEmpty())
    {
        patients[index++] = pq.dequeue();
    }
    for (int i = 0; i < index; i++)
    {
        Patient p = patients[i];
        cout << "Patient Name: " << p.name << ", Priority: ";
        if (p.priority == 1)
            cout << "Serious\n";
        else if (p.priority == 2)
            cout << "Non-serious\n";
        else if (p.priority == 3)
            cout << "General Check-Up\n";
    }
    return 0;
}

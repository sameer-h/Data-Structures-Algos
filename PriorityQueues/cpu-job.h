#ifndef CPU_JOB_H
#define CPU_JOB_H

#include <iostream>

/*
 * CPU_Job holds information for a process to run on the processor
 */
struct CPU_Job {
    int ID;     // process ID
    int length; // process length
    int prior;  // process priority
    CPU_Job(int a = 0, int b = 0, int c = 0) : ID(a), length(b), prior(c) {};
};

/*
 * Operator declarations
 */
bool operator<(const CPU_Job& lhs, const CPU_Job& rhs)
{
    if (lhs.prior < rhs.prior)
    {
        return true;
    }

    if (lhs.length < rhs.length && lhs.prior == rhs.prior)
    {
        return true;
    }

    if (lhs.length == rhs.length && lhs.prior == rhs.prior && lhs.ID < rhs.ID)
    {
        return true;
    }

    return false;
}

std::istream& operator>>(std::istream& in, CPU_Job& job)
{
    in >> job.ID;

    in >> job.length;

    in >> job.prior;

    return in;
}

std::ostream& operator<<(std::ostream& out, const CPU_Job& job)
{
    out << "Job "; out << job.ID;

    out << " with length "; out << job.length;

    out << " and priority "; out << job.prior;

    return out;

}

#endif
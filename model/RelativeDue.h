#ifndef RELATIVEDUE_H
#define RELATIVEDUE_H

enum class RelativeDue {
    Irrelevant,
    Overdue,
    Today,
    Tomorrow,
    ThisWeek,
    NextWeek,
    ThisMonth,
    NextMonth,
    Later
};

#endif // RELATIVEDUE_H

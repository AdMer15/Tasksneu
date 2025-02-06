#include "duedatedelegate.h"
#include <QPainter>
#include <QDateTime>
#include "model/RelativeDue.h"

RelativeDueDelegate::RelativeDueDelegate(QObject* parent) : QStyledItemDelegate(parent)
{}

QString RelativeDueDelegate::displayText(const QVariant& value, const QLocale&) const {

    switch (value.value<RelativeDue>()) { //vlaue.value wandelt einfach den Qvariant wert einfach in einen Enumtyp RelativeDue um.
    case RelativeDue::Irrelevant: return "Irrelevant";
    case RelativeDue::Today: return "Heute";
    case RelativeDue::Tomorrow: return "Morgen";
    case RelativeDue::ThisWeek: return "Diese Woche";
    case RelativeDue::NextWeek: return "Nächste Woche";
    case RelativeDue::ThisMonth: return "Diesen Monat";
    case RelativeDue::NextMonth: return "Nächster Monat";
    case RelativeDue::Later: return "Irgendwann";
    case RelativeDue::Overdue: return "Überfällig";
    default: return "Unbekannt";
    }
}

void RelativeDueDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                                const QModelIndex &index) const {
    QColor fillColor; // das deklariert eine farbe. Diese setze ich dann später. QColor ist auch eine Qt Klasse
    QColor textColor = Qt::black; // Standard-Textfarbe auf Schwarz setzen

    switch (index.data(Qt::DisplayRole).value<RelativeDue>()) {//index.data ruft einfach die gespeicherten werte von meiner Tabelle ab aus den einzelnen Zellen
    case RelativeDue::Overdue:
    case RelativeDue::Today:
    case RelativeDue::Tomorrow:
    case RelativeDue::ThisWeek:
        fillColor = QColor(255, 102, 102); // Rot //hier
        textColor = Qt::white; // Ändere die Textfarbe auf Weiß für bessere Sichtbarkeit
        break;
    case RelativeDue::NextWeek:
        fillColor = QColor(255, 180, 102);  // Orange //hier
        break;
    case RelativeDue::ThisMonth:
    case RelativeDue::NextMonth:
    case RelativeDue::Later:
        fillColor = QColor(102, 255, 102);  // Grün // und hier
        break;
    default:
        fillColor = Qt::lightGray; // einfach als standard hintergrund
    }

    fillColor.setAlpha(200);// macht die Farbe einfach durchsichtiger.

    painter->save();//speichert einfach den aktuellen zustand vom Qpbaint objekt
    painter->fillRect(option.rect, fillColor);//zeichnet ein gefülltes rechteck
    painter->setPen(textColor);//setzt text farbe abhängig vom hintergrund (weiß falls rot, sonst schwarz)
    painter->drawText(option.rect, Qt::AlignCenter, displayText(index.data(Qt::DisplayRole), QLocale()));//einfach nur damit es es in der mitte der zelle steht
    painter->restore(); // setzt den zustand zurück. Das ist wichtig weil der painter für andere zellen verwendet wird
}




/*QSize RelativeDueDelegate::sizeHint(const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const {
    return QStyledItemDelegate::sizeHint(option, index);
}*/

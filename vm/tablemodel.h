#ifndef TASKTABLEMODEL_H
#define TASKTABLEMODEL_H

#include <QAbstractTableModel>
#include "model/task.h"

// Die TaskTableModel-Klasse stellt die Aufgaben-Daten als Tabelle dar.
// Sie erbt von QAbstractTableModel, was bedeutet, dass wir die Datenstruktur und
// das Verhalten der Tabelle selbst definieren können.
class TaskTableModel : public QAbstractTableModel {
    Q_OBJECT  // Qt-Makro für Klassen, die Qt-spezifische Funktionen wie Signale/Slots verwenden.

public:
    // Konstruktor: Initialisiert das Modell, optional mit einem Eltern-Widget.
    explicit TaskTableModel(QObject *parent = nullptr)
        : QAbstractTableModel(parent) {}

    // Funktion zum Setzen der Aufgaben-Liste (Erneuert die Anzeige, wenn neue Daten vorhanden sind).
    void setTasks(const QVector<Task> &tasks) {
        beginResetModel();  // Informiert die Tabelle, dass eine Änderung bevorsteht
        m_tasks = tasks;  // Speichert die neuen Aufgaben
        endResetModel();  // Signalisiert der Tabelle, dass die Daten aktualisiert wurden
    }

    // Gibt die Anzahl der Zeilen zurück, also die Anzahl der Aufgaben.
    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);  // Wir verwenden hier kein Parent-Modell, daher wird es ignoriert.
        return m_tasks.size();  // Die Anzahl der Aufgaben (Anzahl der Zeilen in der Tabelle)
    }

    // Gibt die Anzahl der Spalten zurück. Wir haben fünf Spalten (ID, Beschreibung, Fälligkeitsdatum, Relative Due, Zugewiesene).
    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);  // Parent wird wieder ignoriert.
        return 5;  // 5 Spalten: ID, Beschreibung, Fälligkeitsdatum, Relative Due, Zugewiesene
    }

    // Gibt die Daten für eine bestimmte Zelle zurück, basierend auf Zeile und Spalte.
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        // Überprüft, ob der Index gültig ist und ob die Daten angezeigt werden sollen (DisplayRole).
        if (!index.isValid() || role != Qt::DisplayRole) {
            return QVariant();  // Keine Daten zurückgeben, wenn die Bedingung nicht erfüllt ist
        }

        // Holt die Aufgabe für die aktuelle Zeile
        const Task &task = m_tasks[index.row()];

        // Gibt die Daten basierend auf der Spalte zurück
        switch (index.column()) {
        case 0:
            return task.getId();  // Spalte 0: Die ID der Aufgabe
        case 1:
            return QString::fromStdString(task.getDescription());  // Spalte 1: Die Beschreibung der Aufgabe
        case 2:
            return QString::fromStdString(task.getDue());  // Spalte 2: Das Fälligkeitsdatum der Aufgabe
        case 3:
        {
            RelativeDue dueValue = task.getRelativeDue(today);
            return QVariant::fromValue(dueValue);
            //QString dueText;

            /*switch (dueValue) {
            case RelativeDue::Irrelevant: dueText = "Irrelevant"; break;
            case RelativeDue::Today: dueText = "Heute"; break;
            case RelativeDue::Tomorrow: dueText = "Morgen"; break;
            case RelativeDue::ThisWeek: dueText = "Diese Woche"; break;
            case RelativeDue::NextWeek: dueText = "Nächste Woche"; break;
            case RelativeDue::ThisMonth: dueText = "Diesen Monat"; break;
            case RelativeDue::NextMonth: dueText = "Nächster Monat"; break;
            case RelativeDue::Later: dueText = "Irgendwann"; break;
            case RelativeDue::Overdue: dueText = "Überfällig"; break;
            default: dueText = "Unbekannt"; break;
            }

            qDebug() << "Zeile:" << index.row() << "Relative Due Enum:" << static_cast<int>(dueValue) << " -> Text:" << dueText;
            return dueText;*/
        }

        case 4:
            return QString::fromStdString(task.getAssignee());  // Spalte 4: Die zugewiesenen Personen als kommagetrennte Liste
        default:
            return QVariant();  // Für ungültige Spalten keine Daten zurückgeben
        }
    }

    // Gibt die Überschriften für die Spalten zurück, z. B. "ID", "Beschreibung", etc.
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
        if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
            // Gibt die Überschriften für jede Spalte zurück.
            switch (section) {
            case 0:
                return QString("ID");  // Überschrift für die erste Spalte
            case 1:
                return QString("Description");  // Überschrift für die zweite Spalte
            case 2:
                return QString("Due Date");  // Überschrift für die dritte Spalte
            case 3:
                return QString("Relative Due");
            case 4:
                return QString("Assignees");  // Überschrift für die vierte Spalte
            default:
                return QVariant();  // Für ungültige Spalten keine Überschrift zurückgeben
            }
        }
        return QVariant();  // Für andere Rollen oder Ausrichtungen keine Überschrift zurückgeben
    }

private:
    // Die Liste der Aufgaben, die im Modell gespeichert werden.
    QVector<Task> m_tasks;
    Date today;
};

#endif // TASKTABLEMODEL_H

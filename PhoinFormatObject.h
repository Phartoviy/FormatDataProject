/// \brief Класс Формата данных Phoin
/// \file PhoinFormatObject.h
/// \author Phartoviy
/// 2024 Phoin Ltd.

#ifndef PHOINFORMATOBJECT_H
#define PHOINFORMATOBJECT_H
#include "PTime.h"
#include "PDate.h"
#include <QTime>
#include <vector>
#include <set>
/**
 * @brief Класс описывающий формат данных Phoin
 */
class PhoinFormatObject
{
    std::string nameID{""};//!< имя обьекта(в файле записывается как id)
    std::string line{""};//!< данные
    std::vector<std::string> log{};//!< лог ошибок
    std::vector<PhoinFormatObject> innerLists{};//!< вложенные листы
public:
    PhoinFormatObject();
    PhoinFormatObject(std::string lineId);
    /**
     * @brief Получение имени(id) листа
     * @return Имя
     */
    std::string getName();
    /**
     * @brief Получение целого числа из листа по его тегу
     * @param tag - тег
     * @param result - переменная куда будет записано число
     * @return Выполнено(true)/Невыполнено(false)
     */
    bool getValueInt(std::string tag,int &result);
    /**
     * @brief Получение строки из листа по его тегу
     * @param tag - тег
     * @param result - переменная куда будет записана строка
     * @return Выполнено(true)/Невыполнено(false)
     */
    bool getValueStr(std::string tag,std::string &result);
    /**
     * @brief Получение дробного числа из листа по его тегу
     * @param tag - тег
     * @param result - переменная куда будет записано число
     * @return Выполнено(true)/Невыполнено(false)
     */
    bool getValueDouble(std::string tag,double &result);
    /**
     * @brief Получение времени из листа по его тегу
     * @param tag - тег
     * @param result - обьект куда будет записано время
     * @return Выполнено(true)/Невыполнено(false)
     */
    bool getValueTime(std::string tag,PTime &result);
    /**
     * @brief Получение даты из листа по его тегу
     * @param tag - тег
     * @param result - обьект куда будет записано дата
     * @return Выполнено(true)/Невыполнено(false)
     */
    bool getValueDate(std::string tag,PDate &result);
    /**
     * @brief Получение логического значения из листа по его тегу
     * @param tag - тег
     * @param result - переменная куда будет записано значение
     * @return Выполнено(true)/Невыполнено(false)
     */
    bool getValueBool(std::string tag, bool &result);
    /**
     * @brief Получение вложенного листа по его тегу
     * @param tag - тег
     * @return обьект PhoinFormat
     */
    PhoinFormatObject getFormatList(std::string tag);
    /**
     * @brief Добавление нового атрибута со значением целого числа
     * @param tag - тег
     * @param value - целое число
     * @return Выполнено(true)/Невыполнено(false)
     */
    bool addAttributInt(std::string tag, int value);
    /**
     * @brief Добавление нового атрибута со значением дробного числа
     * @param tag - тег
     * @param value - дробное число
     * @return Выполнено(true)/Невыполнено(false)
     */
    bool addAttributDouble(std::string tag, double value);
    /**
     * @brief Добавление нового атрибута со значением логическое
     * @param tag - тег
     * @param value - логическое значение
     * @return Выполнено(true)/Невыполнено(false)
     */
    bool addAttributBool(std::string tag, bool value);
    /**
     * @brief Добавление нового атрибута время
     * @param tag - тег
     * @param value - обьект время
     * @return Выполнено(true)/Невыполнено(false)
     */
    bool addAttributTime(std::string tag, PTime value);
    /**
     * @brief Добавление нового атрибута дата
     * @param tag - тег
     * @param value - обьект дата
     * @return Выполнено(true)/Невыполнено(false)
     */
    bool addAttributDate(std::string tag, PDate value);
    /**
     * @brief Добавление нового атрибута со значением строка
     * @param tag - тег
     * @param value - строка
     * @return Выполнено(true)/Невыполнено(false)
     */
    bool addAttributStr(std::string tag, std::string value);
    /**
     * @brief Получение словаря всех тегов листа
     * @return словарь тегов
     */
    std::set<std::string> getTags();
    /**
     * @brief Получение тега по его номеру в листе
     * @param num - номер в листе
     * @return тег
     */
    std::string getTagByNO(int num);
    /**
     * @brief Проверка на пустоту листа
     * @return Пуст(true)/не пуст(false)
     */
    bool isEmpty();
    /**
     * @brief Получение количества атрибутов
     * @return количество атрибутов
     */
    int countAttrib();
    /**
     * @brief Получение лога(списка сообщений)
     * @return лог
     */
    std::vector<std::string> getlog();
    /**
     * @brief Получение последнего сообщения
     * @return сообщение
     */
    std::string getRecentLog();
    /**
     * @brief Заполнение обьекта данными
     * @param l - строка с данными
     */
    void setData(std::string l);
    /**
     * @brief Добавление вложенного листа по его тегу
     * @param lineAttribut - данные листа
     * @param tag - тег
     */
    void addInnerList(std::string lineAttribut, std::string tag);
    /**
     * @brief Удаление атрибута по его тегу(даже если это вложенный лист)
     * @param tag - тег
     * @return Выполнено(true)/Невыполнено(false)
     */
    bool deleteAttribut(std::string tag);
private:
    std::string getValue(std::string tag,bool &s);
    bool setValue(std::string attribut);
    PhoinFormatObject getListByNumber(int number);
    int getNumberByTagList(std::string tag);

};

#endif // PHOINFORMATOBJECT_H

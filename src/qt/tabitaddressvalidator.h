// Copyright (c) 2011-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TABIT_QT_TABITADDRESSVALIDATOR_H
#define TABIT_QT_TABITADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class TabitAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit TabitAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Tabit address widget validator, checks for a valid tabit address.
 */
class TabitAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit TabitAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // TABIT_QT_TABITADDRESSVALIDATOR_H

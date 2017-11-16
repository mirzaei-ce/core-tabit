Shared Libraries
================

## tabitconsensus

The purpose of this library is to make the verification functionality that is critical to Tabit's consensus available to other applications, e.g. to language bindings.

### API

The interface is defined in the C header `tabitconsensus.h` located in  `src/script/tabitconsensus.h`.

#### Version

`tabitconsensus_version` returns an `unsigned int` with the the API version *(currently at an experimental `0`)*.

#### Script Validation

`tabitconsensus_verify_script` returns an `int` with the status of the verification. It will be `1` if the input script correctly spends the previous output `scriptPubKey`.

##### Parameters
- `const unsigned char *scriptPubKey` - The previous output script that encumbers spending.
- `unsigned int scriptPubKeyLen` - The number of bytes for the `scriptPubKey`.
- `const unsigned char *txTo` - The transaction with the input that is spending the previous output.
- `unsigned int txToLen` - The number of bytes for the `txTo`.
- `unsigned int nIn` - The index of the input in `txTo` that spends the `scriptPubKey`.
- `unsigned int flags` - The script validation flags *(see below)*.
- `tabitconsensus_error* err` - Will have the error/success code for the operation *(see below)*.

##### Script Flags
- `tabitconsensus_SCRIPT_FLAGS_VERIFY_NONE`
- `tabitconsensus_SCRIPT_FLAGS_VERIFY_P2SH` - Evaluate P2SH ([BIP16](https://github.com/tabit/bips/blob/master/bip-0016.mediawiki)) subscripts
- `tabitconsensus_SCRIPT_FLAGS_VERIFY_DERSIG` - Enforce strict DER ([BIP66](https://github.com/tabit/bips/blob/master/bip-0066.mediawiki)) compliance

##### Errors
- `tabitconsensus_ERR_OK` - No errors with input parameters *(see the return value of `tabitconsensus_verify_script` for the verification status)*
- `tabitconsensus_ERR_TX_INDEX` - An invalid index for `txTo`
- `tabitconsensus_ERR_TX_SIZE_MISMATCH` - `txToLen` did not match with the size of `txTo`
- `tabitconsensus_ERR_DESERIALIZE` - An error deserializing `txTo`

### Example Implementations
- [NTabit](https://github.com/NicolasDorier/NTabit/blob/master/NTabit/Script.cs#L814) (.NET Bindings)
- [node-libtabitconsensus](https://github.com/bitpay/node-libtabitconsensus) (Node.js Bindings)
- [java-libtabitconsensus](https://github.com/dexX7/java-libtabitconsensus) (Java Bindings)
- [tabitconsensus-php](https://github.com/Bit-Wasp/tabitconsensus-php) (PHP Bindings)

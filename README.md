# Bencode Parser

## Bencode
Bencode (pronounced like Ben-code) is the encoding used by the peer-to-peer file sharing system 
BitTorrent for storing and transmitting loosely structured data.

It supports four different types of values:  
* byte strings
* integers
* lists
* dictionaries

Bencoding is most commonly used in torrent files, and as such is part of the BitTorrent specification.

## Description

Bencode parser allows converting **Bencoded data(Torrent files)** into human readable **Json format** written in cpp.
Decoded data returns Json::Value. Used `jsoncpp` library in cpp for handling with json data.

[JsonCpp Github](https://github.com/open-source-parsers/jsoncpp)

## Bencode Parser API's

API's for decoding Bencode data to a Json::Value
```cpp
// decode bencoded int into int
int bencode_decode_int(const std::string &torr_str);
// decode bencoded string into string
std::string bencode_decode_str(const std::string &torr_str);
// decode bencoded list into json
Json::Value bencode_decode_list(const std::string &torr_str);
// decode bencoded dictionary into json
Json::Value bencode_decode_dict(const std::string &torr_str);
Json::Value bencode_decode(const std::string &torr_str);
```

API's for encoding Json::Value into Bencode string
```cpp
// encode int into bencoded string
std::string bencode_encode_int(Json::Value bencode);
// encode string into bencoded string
std::string bencode_encode_str(Json::Value bencode);
// encode json list into bencoded string
std::string bencode_encode_list(Json::Value bencode);
// encode json dictionary into bencoded string
std::string bencode_encode_dict(Json::Value bencode);
std::string bencode_encode(Json::Value bencode);
```


>**_NOTE:_** while using bencode parser, add `-ljsoncpp` compilation flag for linking jsoncpp library

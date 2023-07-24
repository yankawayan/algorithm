import json
from urllib import request
import numpy as np

APPID = "dj00aiZpPVFLUU9jOWhrSWI0cCZzPWNvbnN1bWVyc2VjcmV0Jng9ZmY-"
URL = "https://jlp.yahooapis.jp/MAService/V2/parse"

input_text = "美しい水車小屋の娘は別の小屋に住んでいた。"

def japanese_text_changer(text=input_text):
    def post(query):
        headers = {
            "Content-Type": "application/json",
            "User-Agent": "Yahoo AppID: {}".format(APPID),
        }
        param_dic = {
        "id": "1234-1",
        "jsonrpc": "2.0",
        "method": "jlp.maservice.parse",
        "params": {
            "q": query
        }
        }
        params = json.dumps(param_dic).encode()
        req = request.Request(URL, params, headers)
        with request.urlopen(req) as res:
            body = res.read()
        return body.decode()

    res_json = post(input_text)
    res_dic = json.loads(res_json)
    output = res_dic["result"]["tokens"]

    words = [list[0] for list in output]

    word_to_id = {}
    id_to_word = {}
    sentense_and_words = {}
    list_words = []

    for word in words:
        list_words.append(word)
        if word not in word_to_id:
            new_id = len(word_to_id)
            word_to_id[word] = new_id
            id_to_word[new_id] = word

    sentense_and_words["sentense"] = input_text
    sentense_and_words["words"] = list_words


    corpus = [word_to_id[w] for w in words]
    corpus = np.array(corpus)

    print(corpus)

    return word_to_id,id_to_word,sentense_and_words,corpus
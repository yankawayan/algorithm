import numpy as np

input_text = "美しい水車小屋の娘は別の小屋に住んでいた。"

corpus = np.array([0,1,2,3,4,5,6,2,7,8,9,10])
sentense_and_words = {'sentense':'美しい水車小屋の娘は別の小屋に住んでいた。',\
                    'words': ['美しい','水車','小屋','の','娘','は','別の','小屋','に','住んで','いた','。']}
word_to_id={'美しい':0,'水車':1,'小屋':7,'の':3,'娘':4,'は':5,'別の':6,'に':7,'住んで':8,'いた':9,'。':10}
id_to_word={0:'美しい',1:'水車',2:'小屋',3:'の',4:'娘',5:'は',6:'別の',7:'に',8:'住んで',9:'いた',10:'。'}

#window sizeを左右1 input_textの共起行列
def create_co_matrix(corpus,vocab_size,window_size=1):
    corpus_size = len(corpus)
    co_matrix = np.zeros((vocab_size,vocab_size),dtype=np.int32)

    for idx, word_id in enumerate(corpus):
        for i in range(1,window_size+1):
            left_idx = idx - i
            right_idx = idx + i

            if left_idx >= 0:
                left_word_id = corpus[left_idx]
                co_matrix[word_id,left_word_id] += 1

            if right_idx < corpus_size:
                right_word_id = corpus[right_idx]
                co_matrix[word_id, right_word_id] += 1

    return co_matrix

def cos_similarity(x,y,eps=1e-8):
    nx = x / np.sqrt(np.sum(x**2)+eps)
    ny = y / np.sqrt(np.sum(y**2)+eps)
    return np.dot(nx, ny)

C = create_co_matrix(corpus,len(word_to_id))

def most_similar(query,word_to_id,id_to_word,word_matrix,top=5):
    #クエリを取り出す
    if query not in word_to_id:
        print('{} is not found'.format(query))
        return
    
    print('\n[query]'+ query)
    query_id = word_to_id[query]
    query_vec = word_matrix[query_id]

    #コサイン類似度の算出
    vocab_size = len(id_to_word)
    
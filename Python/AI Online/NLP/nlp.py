from nltk.tokenize import word_tokenize
from nltk.probability import FreqDist
s = """The Indian subcontinent, the great landmass of South Asia, is the home of one of the world’s oldest 
and most influential civilizations. In this article, the subcontinent, which for historical purposes is 
usually called simply “India,” is understood to comprise the areas of not only the present-day Republic of 
India but also the republics of Pakistan (partitioned from India in 1947) and Bangladesh 
(which formed the eastern part of Pakistan until its independence in 1971). For the histories of these 
latter two countries since their creation, see Pakistan and Bangladesh."""
tok = word_tokenize(s)
fdist = FreqDist()
for i in tok:
    fdist[i.lower()]+=1
for i in fdist:
    print(i, fdist[i])
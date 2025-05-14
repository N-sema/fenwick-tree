
## Fenwick tree ( Binary Indexed Tree - BIT)

Fenwick Tree , bir dizi üzerindeki prefix sum (ön toplam) gibi işlemleri verimli şekilde gerçekleştirmek için kullanılan bir veri yapısıdır. Özellikle güncelleme ve toplam alma işlemleri için tercih edilir . Kısaca bir dizideki belirli bir indise kadar olan tüm değerlerin toplamını bulmaya yarar  


## Temel özellikleri 
-Prefix sum (örnek toplam ) Hesaplama  
-Güncelleme:
Dizideki bir elemanın değerini değiştirmek, diğer elemanları da etkilemeden güncellenebilir
-Bellek kullanımı:
Dizinin kendisi ile aynı boyutta bellek kullanır


## Avantajları ve Dezavantajları 

Avantajları
- zaman verimliliği (O(logn) karmaşıklığa sahip )
- basitlik (uygulaması kolay )
- alan verimliliği (O(n) kadar yer kaplar )
- büyük veri setlerinde hızlıdır  

Dezavantajları 
- sadece toplama işlemleri için uygun 
- aralık güncellemeleri zor 


## Karmaşıklık analizi
Güncelleme ve sorgu işlemi için O(log n) kullanır. Bu nedenle büyük veri setlerinde özellikle sıklıkla yapılan sorgulamalar ve güncellemeler için çok etkiilidir


## Kullanım alanları:
-Aralık toplamı hesaplama: Bir dizinin belirli bir aralığındaki toplamı hızlıca hesaplamak için kullanılabilir 
-Veri tabanı sorguları: Veri tabanında belirli bir koşula göre verilerin toplamını hesaplamak için kullanılabilir.
-Rekabetçi programlama: Çeşitli algoritmik problemlerin çözümü için kullanılabir



## Nasıl Çalışır:

-Dizi Temsili:
Fenwick Tree, genellikle 1 tabanlı diziler kullanır. Bu, indekslerin 1’den başladığı anlamına gelir. Bu özellik, binary işlemleri daha kolay ve anlaşılır hale getirir.

-Güncelleme (Update) İşlemi:
Fenwick Tree’de, bir eleman güncellendiğinde, sadece o elemanın bağlı olduğu bir dizi öğe güncellenir. Güncelleme işlemi, O(log n) zaman alır.

-Sorgulama (Query) İşlemi:
Bir aralıktaki toplamı sorgulamak için, Fenwick Tree'deki prefix toplamları üzerinden gidilir. Örneğin, sum(1...i) sorgusu yapılırken, yalnızca ilgili bit düzeyindeki öğelere bakılır.


## ÖRNEK


[1,2,3,4,5]'ten oluşan bir listeniz olduğunu düşünelim

İlk Liste: 
[1,2,3,4,5]

Fenwick Ağacı: Başlangıçta sıfırlardan oluşan bir diziydi ve önek toplamlarını depolamak için güncellendi.
Güncelleme Fonksiyonu
update(i, value)` → `bit[i]`, `bit[i + (i & -i)]` gibi ilgili düğümler güncellenir.

update(1, 1)
update(2, 2)
update(3, 3)
update(4, 4)
update(5, 5)


Fenwick Ağacı'nın listeye göre güncellenmesinin ardından su şekilde görünür


bit[1] = 1 → sadece arr[1]

bit[2] = 3 → arr[1] + arr[2]

bit[3] = 3 → sadece arr[3]

bit[4] = 10 → arr[1] + arr[2] + arr[3] + arr[4]

bit[5] = 5 → sadece arr[5] 

Dizin:  1 2 3 4 5

Değer:  1 3 3 10 5



KAYNAKÇA
A new data structure for cumulative frequency tables", Software: Practice and Experience, 24(3), 327–336.

TopCoder Tutorials – Binary Indexed Trees



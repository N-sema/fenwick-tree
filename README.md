
## Fenwick Tree ( Binary Indexed Tree - BIT)


Fenwick Tree, bir dizideki belirli bir indise kadar olan ön toplamları (prefix sum) hızlıca hesaplamak ve elemanları güncellemek için kullanılan özel bir veri yapısıdır.

Hem sorgulama (query) hem de güncelleme (update) işlemleri O(log n) zaman karmaşıklığında yapılır.  





## Temel özellikleri 

-Prefix sum (örnek toplam ) Hesaplama  
-Güncelleme:
Dizideki bir elemanın değerini değiştirmek, diğer elemanları da etkilemeden güncellenebilir
-Bellek kullanımı:
Dizinin kendisi ile aynı boyutta bellek kullanır


## Çözüm Yaklaşımı 

Fenwick Tree’nin temelinde ikilik (binary) sayı sistemi ve bit düzeyinde işlemler (bit manipülasyonu) yer alır. Bu yapı, dizideki bazı toplamları (örneğin prefix sum) saklamak ve hızlı sorgulamalar yapabilmek için özel bir şekilde tasarlanmıştır.

Güncelleme ve sorgulama işlemleri, indekslerin ikili gösterimindeki en düşük pozitif (1 olan) bitten yararlanılarak yapılır. Bu bite RSB (rightmost set bit) denir.

Fenwick Tree’de her hücre, dizideki belirli bir aralık (segment) üzerindeki toplamdan sorumludur. Hangi hücrenin hangi aralığı kapsadığı, hücrenin indeksinin ikili (binary) gösteriminde sağdan ilk "1" bitinin bulunduğu pozisyona göre belirlenir. Bu sayede her hücre, önceden belirlenmiş bir alt aralığın toplamını temsil eder.



## Ne Zaman Kulanılır

-Prefix Sum (Ön Toplam) işlemlerinin sık yapıldığı durumlarda
-Sürekli güncellenen bir dizi varsa
-Zaman karmaşıklığı önemliyse
-Çok sayıda range-sum ve tekli update işlemi gerekiyorsa Fenwick Tree kullanılabilir


## Neden Fenwick Tree ?
- Hızlı
- Bellek Dostu 
- Kolay Kodlanabilir
- Rekabetçi Prgramlama için ideal 


## Karmaşıklık analizi

-Zaman Karmaşıklığı 
Güncelleme ve sorgu işlemi için O(log n) kullanır. Bu nedenle büyük veri setlerinde özellikle sıklıkla yapılan sorgulamalar ve güncellemeler için çok etkilidir

- Uzay Karmaşıklığı 
O (n) karmaşıklığına sahiptir 



## Avantajları ve Dezavantajları 

Avantajları
- zaman verimliliği (O(logn) karmaşıklığa sahip )
- basitlik (uygulaması kolay )
- alan verimliliği (O(n) kadar yer kaplar )
- büyük veri setlerinde hızlıdır  

Dezavantajları 
- sadece toplama işlemleri için uygun 
- aralık güncellemeleri zor 




## Kullanım alanları:
-Aralık toplamı hesaplama: Bir dizinin belirli bir aralığındaki toplamı hızlıca hesaplamak için kullanılabilir 
-Veri tabanı sorguları: Veri tabanında belirli bir koşula göre verilerin toplamını hesaplamak için kullanılabilir.
-Rekabetçi programlama: Çeşitli algoritmik problemlerin çözümü için kullanılabir


## Kullanım Yerlerine Örnekler 
- Veri Bilimi ve İstatistik
- Oyun Geliştirme
- Yapay Zeka
- Genetik ve Biyoinformatik 
- veri tabanı ve Sorgulama Sistemleri
- Zaman Serisi Verileri


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



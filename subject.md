Minishell Subject

Kelime Sözlüğü
Shell			: Kabuk
Introduction	: Giriş
Summary			: Özet
Mandatory Part	: Zorunlu Kısım
Prompt			: Bilgi istemi. Userdan herhangi birşey girmesi için hazır durumda bekleyen shell satırı.
History			: Geçmiş
PATH			: Dosya yolu. Path(Yol) unique(eşsiz, özel) olarak bir işletim sisteminde bir dosya yada klasöre verilen özel bir lokasyondur. Path bir dosya yolunun alfa sayısal karakterlerin birleşiminden oluşur. Kısaca diyebiliriz ki, bir dosya yada klasörün lokal yolu olarak diyebiliriz.
Backslash		: \ ters slash işareti. Kaçma Operatörü
semicolon		: ; noktalı virgül işareti. İfade sonlandırma operatörü.
Quote			: ' (tek tırnak) veya " (çift tırnak)	
Redirect		: Yönlendirme

Keywords
	- Shell
	- Unix Shell
	- Bash
	- Process
	- File Descriptor
	- Prompt
	- History
	- Executable
	- Search
	- Launch
	- PATH varible
	- Relative Path
	- Absolute Path
	- Global Variable
	- Metacharacters
	- Redirections
	- Input
	- Output
	- Append Mode
	- Pipes
	- Environment Variables
	- Builtins (yerleşik komutlar)
	- Readline

Summary
	Bu proje basit bir shell yazılımı oluşturmakla ilgilidir.
	Evet, kendi küçük bash yazılımımız diyebiliriz.
	Process ve File descriptor hakkında çok şey öğreneceğiz.


Introduction
	Shell'in varlığı IT'nin(bilişim teknolojilerinin) varlığıyla bağlantılıdır. Bilgisayarların ilk çıktığı zamanlarda tüm geliştiriciler hizalanmış 0 | 1 anahtarlarını kullanarak bilgisayarla iletişim kurmanın ciddi şekilde rahatsız edici olduğu konusunda hemfikirlerdi.

	Bilgisayarla etkileşim kurabilmek için; insan diline daha yakın bir dil ile, komut satırları kullanılarak "bilgisayar ve insan arasında iletişim" sağlayan "yazılım geliştirme" fikri gayet mantıklıydı.

	Minishell sayesinde, zamanda yolculuk yapabilecek ve Windows işletim sistemi yokken insanların karşılaştığı sorunlara geri dönebileceksiniz.

Mandatory Part
	Program name
		- minishell
	Turn in files
		- Makefile, *.h, *.c
	External functs
		- readline(), rl_clear_history(), rl_on_new_line(), rl_replace_line(), rl_redisplay()
		- add_history()
		- printf(), malloc(), free()
		- write(), access(), open(), read(), close()
		- fork(), wait(), waitpid(), wait3(), wait4()
		- signal(), sigaction(), sigemptyset(), sigaddset()
		- kill(), exit()
		- getcwd()
		- chdir()
		- stat(), lstat(), fstat()
		- unlink()
		- execve()
		- dup(), dup2()
		- pipe()
		- opendir(), readdir(), closedir(), strerror(), perror()
		- isatty(), ttyname(), ttyslot()
		- ioctl()
		- getenv()
		- tcsetattr(), tcgetattr()
		- tgetent(), tgetflag(), tgetnum, tgetstr()
		- tgoto()
		- tputs()
	Libft authorized
		- yes
	Description
		- shell yaz

	Yazdığımız Shell'imiz aşağıdakiler gibi olmalıdır:
		- minishell komut bekleme konumundayken bir "prompt" göstermelidir.
    		-[scakmak@k1m41s06 minishell %								]
		- Kod geçmişi tutan "History" yapısı olmalı.
		- Executable (yani çalıştırılabilir) dosyaları "PATH  değişkeninde" veya "relative path" veya "absolute path" ile verilmiş olabilir.Dosyayı verilen yol içerisinde aramalısın. Ara varsa başlat.
		- Sadece 1 adet "global variable" kullanabiliriz. Fazlası yasak. Global değişken kullanma amacımızı açıklayabilmeliyiz.
		- Kapatılmamış tırnakları veya \ (Ters eğik çizgi) veya ; (noktalı virgül) gibi konunun gerektirmediği özel karakterleri yorumlamayın.
		- ' (tek tırnak) meta karakterlerin (< > >> << * ? [ ] | ; & () # $ \ ) yorumlanmasını engellemelidir.
		- " (çift tırnak) $ hariç tüm meta karakterlerin yorumlanmasını engellemelidir.
		- Redirectionları ekleyin
    		- < (küçüktür meta karakteri) input'u (girişi) yönlendirmelidir
    		- > (büyüktür meta karakteri) output'u (çıkışı) yönlendirmelidir
    		- << meta karakteri bir sınırlayıcı almalı ardından bu sınırlayıcıyı tekrar görene kadar input okumaya devam etmelidir.  Ancak, geçmişi güncellemek zorunda değildir!
    		- >> meta karakteri output'u append (ekleme) modunda yönlendirmelidir.
  		- Pipe 'ları (| meta karakterini) ekleyin. Pipeline (boru hattındaki) her komutun output'u (çıkışı), bir sonraki komutun input'una (girişine) pipe aracılığı ile bağlanmalıdır.
  		- Environment Variables (ortam değişkenleri) nin değerlerini işleyin.($ karakterinden sonra gelen değişken adındaki değer).
  		- $? bilgi değişkenini hallet. En son çalışan pipelinenın exit statusunu (çıkış durumunu) $? içine yükler. Yani $? echo ile yazdırılmaya çalışıldığında bu env çıkış durumu bilgisine genişler ve o bilgiyi bize verir.
  		- Bash'deki gibi davranması gereken ctrl-C, ctrl-D ve ctrl-\ sinyallerini halledin.
    		- ctrl-C displays a new prompt on a new line.
    		- ctrl-D exits the shell.
    		- ctrl-\ does nothing.
  		- Minishell'imiz aşağıdaki builtin'leri eklemelidir.
    		- echo komutu -n seçeneği ile
    		- cd komutu, yalnızca relative path veya absolute path ile çalışmalı.
    		- pwd komutu opsiyonlar olmadan sadece pwd
    		- export komutu opsiyonlar olmadan
    		- unset komutu opsiyonlar olmadan
    		- env komutu opsiyonlar ve arguments olmadan
    		- exit komutu opsiyonlar olmadan
  		- Readline() işlevi bellek sızıntılarına neden olabilir. Onları düzeltmek zorunda değilsin. Ancak bu kendi kodunuz anlamına gelmez, evet yazdığınız kodda bellek sızıntısı olabilir.

UYARI!
	Kendinizi konu açıklamasıyla sınırlandırmalısınız. Sorulmayan hiçbir şey gerekli değildir. Bir gereksinim hakkında herhangi bir şüpheniz varsa, referans olarak bash alın.

Keywords Description

Shell
	- Shell programlama, Unix ve benzeri sistemlerde sistem yönetimini sağlayan komutlar ve bu komutları işlemeye yarayan kontrol mekanizmalarının bulunduğu programlama şeklidir.
	- Shell'in görevi kullanıcı ile kernel arasında aracı bir katman olarak kullanıcıdan gelen girdileri kernele uygun şekilde iletmektir.
	- Özetle shell işletim sistemi ile konuşabilmemizi sağlayan aracı yazılımdır.

Unix Shell
	- Unix shell, Unix benzeri işletim sistemleri için bir CLUI or CLI (Command Line user Interface) komut satırı kullanıcı arabirimi sağlayan bir komut satırı yorumlayıcısı veya kabuğudur.

Bash
  	- Bourne Shell'ine alternatif olarak özgür yazılım tarafından The Bourne Again Shell olarak yeniden yazılan komut satırı kullanıcı arabirimi, komut satırı yorumlayıcısıdır. Unix ve Linux sistemlerde en çok tercih edilen shell diyebiliriz.

Process
	- Bilgisayarlarda çalışan her program aslında bir processdir. Kendir içerisinde donanımdan kaynaklar barındırır ve bunları bölümlendirir. İçerisinde thread/threadler bulunur.

File Descriptor
	Wiki
	- Unix ve Unix benzeri bilgisayar işletim sistemlerinde, bir dosya tanımlayıcı, bir dosya veya bir boru veya ağ soketi gibi diğer giriş / çıkış kaynakları için benzersiz bir tanımlayıcıdır.
	Me
	- File desriptor bilgisayarda bulunan işletim sisteminde açık olan dosyayı benzersi bir id değeriyle tanımlama işlemidir. Bu id leri tutan bir tablo vardır. Aynı şekilde ağ soketi içinde aynı işlemi uygular.
Prompt
	- Kullanıcıdan komut bekleyen (komut istemcisi) terminal satırına verilen isimdir. Herhangi bir shell açtığımız zaman direkt olarak bunu görebilirsiniz. Kullanıcı adı vs. yazan ve birşeyler yazmamızın beklendiği o satır prompt tur.

History
	- Sheller çalıştırılan komutların geçmişini tutar.

Executable
	- Unix & Linux tabanlı sistemlerde tanımlı olan çalıştırılabilir hazır komutlar. PATH Env ında tanımlı klasörlerin aldında bulunan komut dosyalarının tamamı buna örnektir.

Search
	- Arama yapmak. Bu projede searchden kastı ise işletim sisteminde belirttiğimiz komutun PATH ler içerisinde yani çalıştırılabilir komutların tutulduğu klasörlerin altında olup olmadığıdır.

Launch
	- Başlatmak anlamında olan launch. Komut dosyalarının çalıştırılması anlamında kullanılmaktadır. Örneğin Bin/ls altında bulunan ls komutunu barındıran dosyanın çalıştırılması.

PATH Variable (PATH env değişkeni)
	- Bu değişkeni /usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Library/Apple/usr/bin:/Users/scakmak/goinfre/nodejs/bin:/Users/scakmak/goinfre/nodejs/bin böyle bir veri tutar. Bunlar çalıştırılabilir komutların tutulduğu dosya yollarıdır.
Relative Path
	- Dinamik olarak yol verme işlemidir. Relative Path işlemi çalışılmakta olan klasör içerisinde path alma işlemine denir. Örneğin cd .. diyerek path veriyoruz ama uzun olarak değil bir hedefi göstererek.

Absolute Path
	- Absolute path ise bir dosya yada klasörün root(kök) dizinden itibaren verilen path’e denir.
	- Root (/) dizininden itibaren alt klasörler üzerinde çalışmalarınızı gerçekleştirebilirsiniz.
	- Fakat Absolute Path işlemi, genellikle pek tavsiye edilmeyen bir path verme işlemidir.
	- Sebebine gelirsek, Projemize locale olarak Path veriyoruz fakat projemizi farklı makinalar da çalıştırmak istediğimiz zaman verilen Absolute Path(Locale Path) projenin patlamasına sebebiyet vermektedir.
	- Bu yüzden çoğunlukla Relative Path tercih edilmektedir.

Path Example
	Relative Path
		- index.html
		- /graphics/image.png
		- home/about/about.html

	Absolute Path
		- https://www.mysite.com/index.html
		- https://www.mysite.com/graphics/image.png
		- https://www.mysite.com/home/about/about.html
		- /Users/scakmak/Desktop/brain/pdf -> root kök dizinden itibaren olan local kesin yol

Global Variable
	- Bilgisayar programlamasında, global bir değişken, global kapsamı olan bir değişkendir, yani gölgeli olmadığı sürece program boyunca görülebilir. 
	- Program içerisinde programın heryerinden erişilebilir olan değişkenlere global değişken denir.

Metacharacters
	- Meta karakter, shell (kabuk) yorumlayıcı veya normal ifade motoru gibi bir bilgisayar programı için özel bir anlamı olan bir karakterdir.
	- Shell yazılımları için meta karakterleri ise 
    	- >		Output (çıkış) yönlendirme.	ls > bilgi.txt ls komutundan dönen output'u çıktıyı bilgi.txt dosyasına yönlendirir.
    	- >>	Append modda output yönlendirme.
    	- <		Input (giriş) yönlendirme
    	- *		Wildcard Dosya adı değiştirme. Bundan kasıt belirli bir kesim dosya adına işaret etme. Örneğin rm *.c dosya adı fark herhangi birşey olan .c uzantılı dosyaları sil.
    	- ?		Single Wildcard Dosya adı değiştirme tek karakter. Burada dosya adından 1 karaktere ne gelirse gelebilir diye işaret edilebilir. Örneğin rm k?r.c dediğimizde ikinci harfi farketmeksizin k ile başlayan r ile biten 3 harflileri siler. kar.c kir.c kör.c kır.c kor.c
    	- []	List Wildcard Dosya adı değiştirme [] arasında belirlenen karakter listesi ile. cat f[123] komutu ile ilk harfi f olan sonrasında ise bu karakterlerden herhangi biri gelebilecek olan dosya adları. cat f1, cat f2, cat f3
    	- |		Pipe iki program arasındaki girdi çıktı olaylarını birbirlerine köprü olarak bağlar
    	- ||	Veya koşullu yürütme. Bir tanesi çalışmasa bile diğer komut satırını çalıştırır.
    	- ;		Komut dizisi / dizileri. ; ler koyarak birden fazla komut çalıştırabiliriz.
    	- &&	Ve koşullu yürütme. Komutlardan herhangi biri çalışmazsa false olursa tüm komutun çalışmasını durdurur.
    	- ()	Komut grupları. (ls ; pwd)
    	- &		Komutu arka planda çalıştır, Arka Plan İşlemleri
    	- #		Yorum
    	- $		Değişkenin Değerini genişletir.
    	- \		Bir sonraki karakterin yorumlanmasını engelle veya kaçın
    	- <<	Koşullu Giriş yönlendirmesi. Kullanıcıdan girdi bekler. Kendisinden sonra verilen argüman girilene kadar giriş değeri almaya devam eder.

Redirections
	- < > << >> File descriptor ile belirtilenler arasında Girdi ve çıktıları yönlendirmek için kullanılan meta karakterlerdir.

Input
	- Girdi. Bilgisayarda girdi almak stdin ile yani file descriptor 0 ile olur. Veya başkalarının çıktısı belirlenen başka fd değerlerine girdi olabilir.

Output
	- Çıktı. herhangi bir işlemle ortaya çıkan değeri çıktı olarak vermek.

Append Mode
	- Dosya işlemlerinde append mode üzerine ekle demektir. Veriyi yönlendirirken (>> output) çıktı girişte alınıp mevcut veri ile birleştirilir.
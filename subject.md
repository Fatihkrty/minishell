Minishell Subject

Kelime Sözlüğü
Shell			: Kabuk
Introduction	: Giriş
Summary			: Özet
Mandatory Part	: Zorunlu Kısım
Prompt			:
History			:
PATH			:
Backslash		:
semicolon		:
Quote			:
Redirect		:



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
	- Input" >>>>>>                         >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><```<>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
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
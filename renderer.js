document.addEventListener('DOMContentLoaded', () => {
  document.getElementById('node-version').textContent = process.versions.node;
  document.getElementById('chrome-version').textContent = process.versions.chrome;
  document.getElementById('electron-version').textContent = process.versions.electron;
  document.getElementById('platform').textContent = process.platform;
});

function showResult(content) {
  const resultArea = document.getElementById('result-area');
  const resultContent = document.getElementById('result-content');

  resultContent.innerHTML = content;
  resultArea.style.display = 'block';

  setTimeout(() => {
    resultArea.scrollIntoView({ behavior: 'smooth', block: 'start' });
  }, 100);
}

function showLoading(message = 'İşlem devam ediyor...') {
  showResult(`
    <div style="text-align: center; padding: 2rem;">
      <div style="display: inline-block; width: 40px; height: 40px; border: 4px solid #6366f1; border-top: 4px solid transparent; border-radius: 50%; animation: spin 1s linear infinite;"></div>
      <p style="margin-top: 1rem; color: #cbd5e1;">${message}</p>
    </div>
    <style>
      @keyframes spin {
        0% { transform: rotate(0deg); }
        100% { transform: rotate(360deg); }
      }
    </style>
  `);
}

function testMathFunctions() {
  showLoading('Matematik fonksiyonları test ediliyor...');

  try {
    const nativeAddon = require('./build/Release/native_addon');

    let results = '<h4>🧮 Matematik Fonksiyonları Test Sonuçları</h4>';

    const num1 = 25;
    const num2 = 144;

    results += `<div><strong>Karekök(${num1}):</strong> ${nativeAddon.calculateSquareRoot(num1)}</div>`;
    results += `<div><strong>Karekök(${num2}):</strong> ${nativeAddon.calculateSquareRoot(num2)}</div>`;

    const fibNum = 20;
    results += `<div><strong>Fibonacci(${fibNum}):</strong> ${nativeAddon.calculateFibonacci(fibNum)}</div>`;

    const factNum = 10;
    results += `<div><strong>Faktöriyel(${factNum}):</strong> ${nativeAddon.calculateFactorial(factNum)}</div>`;

    // Asal sayı kontrolü
    const primeNum = 97;
    results += `<div><strong>${primeNum} asal mı?:</strong> ${nativeAddon.isPrime(primeNum) ? 'Evet ✅' : 'Hayır ❌'}</div>`;

    showResult(results);
  } catch (error) {
    showResult(`
      <div style="color: #ef4444;">
        <h4>❌ Hata Oluştu</h4>
        <div><strong>Hata:</strong> ${error.message}</div>
        <div style="margin-top: 1rem; padding: 1rem; background: #1e293b; border-radius: 8px;">
          <strong>Çözüm:</strong> Native addon henüz derlenmemiş. Aşağıdaki komutu çalıştırın:<br>
          <code style="color: #10b981;">npm run rebuild</code>
        </div>
      </div>
    `);
  }
}

function testAdvancedMath() {
  showLoading('Gelişmiş matematik fonksiyonları test ediliyor...');

  try {
    const nativeAddon = require('./build/Release/native_addon');

    let results = '<h4>📐 Gelişmiş Matematik Test Sonuçları</h4>';

    const angle = 45;
    results += `<div><strong>Sin(${angle}°):</strong> ${nativeAddon.calculateSin(angle)}</div>`;
    results += `<div><strong>Cos(${angle}°):</strong> ${nativeAddon.calculateCos(angle)}</div>`;
    results += `<div><strong>Tan(${angle}°):</strong> ${nativeAddon.calculateTan(angle)}</div>`;

    const logNum = 100;
    results += `<div><strong>Log₁₀(${logNum}):</strong> ${nativeAddon.calculateLog10(logNum)}</div>`;
    results += `<div><strong>Ln(${logNum}):</strong> ${nativeAddon.calculateLn(logNum)}</div>`;

    const base = 2,
      exponent = 10;
    results += `<div><strong>${base}^${exponent}:</strong> ${nativeAddon.calculatePower(base, exponent)}</div>`;

    showResult(results);
  } catch (error) {
    showResult(`<div style="color: #ef4444;"><strong>Hata:</strong> ${error.message}</div>`);
  }
}

function getDetailedSystemInfo() {
  showLoading('Sistem bilgileri toplanıyor...');

  try {
    const nativeAddon = require('./build/Release/native_addon');
    const os = require('os');

    let results = '<h4>💻 Detaylı Sistem Bilgileri</h4>';

    results += '<h5 style="color: #8b5cf6; margin-top: 1.5rem;">📊 JavaScript Katmanı:</h5>';
    results += `<div><strong>Platform:</strong> ${os.platform()}</div>`;
    results += `<div><strong>Mimari:</strong> ${os.arch()}</div>`;
    results += `<div><strong>CPU Çekirdek Sayısı:</strong> ${os.cpus().length}</div>`;
    results += `<div><strong>Toplam RAM:</strong> ${Math.round(os.totalmem() / 1024 / 1024 / 1024)} GB</div>`;
    results += `<div><strong>Boş RAM:</strong> ${Math.round(os.freemem() / 1024 / 1024 / 1024)} GB</div>`;
    results += `<div><strong>Sistem Çalışma Süresi:</strong> ${Math.round(os.uptime() / 3600)} saat</div>`;

    const systemInfo = nativeAddon.getDetailedSystemInfo();
    results += '<h5 style="color: #10b981; margin-top: 1.5rem;">🔧 Native C++ Katmanı:</h5>';
    results += `<div><strong>CPU Kullanımı:</strong> ${systemInfo.cpu_usage}%</div>`;
    results += `<div><strong>Bellek Kullanımı:</strong> ${systemInfo.memory_usage}%</div>`;
    results += `<div><strong>Disk Kullanımı:</strong> ${systemInfo.disk_usage}%</div>`;
    results += `<div><strong>Process ID:</strong> ${systemInfo.process_id}</div>`;
    results += `<div><strong>Thread Sayısı:</strong> ${systemInfo.thread_count}</div>`;
    results += `<div><strong>Sistem Süresi (ms):</strong> ${systemInfo.system_time}</div>`;

    showResult(results);
  } catch (error) {
    const os = require('os');
    let results = '<h4>💻 Sistem Bilgileri (JavaScript)</h4>';
    results += `<div><strong>Platform:</strong> ${os.platform()}</div>`;
    results += `<div><strong>Mimari:</strong> ${os.arch()}</div>`;
    results += `<div><strong>CPU Çekirdek Sayısı:</strong> ${os.cpus().length}</div>`;
    results += `<div><strong>Toplam RAM:</strong> ${Math.round(os.totalmem() / 1024 / 1024 / 1024)} GB</div>`;
    results += `<div><strong>Boş RAM:</strong> ${Math.round(os.freemem() / 1024 / 1024 / 1024)} GB</div>`;
    results += `<div style="color: #f59e0b; margin-top: 1rem;"><strong>⚠️ Native addon yüklenmedi:</strong> ${error.message}</div>`;
    showResult(results);
  }
}

function testPerformance() {
  showLoading('Performans testleri çalıştırılıyor...');

  try {
    const nativeAddon = require('./build/Release/native_addon');

    let results = '<h4>⚡ Performans Test Sonuçları</h4>';

    const iterations = 1000000;

    const jsStart = performance.now();
    let jsSum = 0;
    for (let i = 0; i < iterations; i++) {
      jsSum += Math.sqrt(i);
    }
    const jsTime = performance.now() - jsStart;

    const nativeResult = nativeAddon.performanceTest(iterations);

    results += '<h5 style="color: #8b5cf6; margin-top: 1.5rem;">📊 Performans Karşılaştırması:</h5>';
    results += `<div><strong>Test İterasyonu:</strong> ${iterations.toLocaleString()} döngü</div>`;
    results += `<div><strong>JavaScript Süresi:</strong> ${jsTime.toFixed(2)} ms</div>`;
    results += `<div><strong>Native C++ Süresi:</strong> ${nativeResult.execution_time} ms</div>`;
    results += `<div><strong>Hız Kazancı:</strong> ${(jsTime / nativeResult.execution_time).toFixed(2)}x daha hızlı</div>`;
    results += `<div><strong>JavaScript Sonuç:</strong> ${jsSum.toFixed(2)}</div>`;
    results += `<div><strong>Native C++ Sonuç:</strong> ${nativeResult.result}</div>`;

    showResult(results);
  } catch (error) {
    showResult(`<div style="color: #ef4444;"><strong>Hata:</strong> ${error.message}</div>`);
  }
}

function testFileOperations() {
  showLoading('Dosya işlemleri test ediliyor...');

  try {
    const nativeAddon = require('./build/Release/native_addon');

    let results = '<h4>📁 Dosya İşlemleri Test Sonuçları</h4>';

    const testContent = 'Bu bir test dosyasıdır.\nNative C++ ile oluşturuldu.\n🚀 Electron Native Addon Test';
    const fileName = 'test_native_file.txt';

    const writeResult = nativeAddon.writeFile(fileName, testContent);
    results += `<div><strong>Dosya Yazma:</strong> ${writeResult ? 'Başarılı ✅' : 'Başarısız ❌'}</div>`;

    const readContent = nativeAddon.readFile(fileName);
    results += `<div><strong>Dosya Okuma:</strong> ${readContent ? 'Başarılı ✅' : 'Başarısız ❌'}</div>`;

    if (readContent) {
      results += `<div style="background: #1e293b; padding: 1rem; border-radius: 8px; margin: 1rem 0;">
        <strong>Okunan İçerik:</strong><br>
        <pre style="color: #10b981; margin: 0.5rem 0;">${readContent}</pre>
      </div>`;
    }

    const fileInfo = nativeAddon.getFileInfo(fileName);
    if (fileInfo) {
      results += `<div><strong>Dosya Boyutu:</strong> ${fileInfo.size} byte</div>`;
      results += `<div><strong>Oluşturma Zamanı:</strong> ${fileInfo.created}</div>`;
      results += `<div><strong>Değiştirilme Zamanı:</strong> ${fileInfo.modified}</div>`;
    }

    const deleteResult = nativeAddon.deleteFile(fileName);
    results += `<div><strong>Dosya Silme:</strong> ${deleteResult ? 'Başarılı ✅' : 'Başarısız ❌'}</div>`;

    showResult(results);
  } catch (error) {
    showResult(`<div style="color: #ef4444;"><strong>Hata:</strong> ${error.message}</div>`);
  }
}

function testEncryption() {
  showLoading('Şifreleme testleri çalıştırılıyor...');

  try {
    const nativeAddon = require('./build/Release/native_addon');

    let results = '<h4>🔐 Şifreleme Test Sonuçları</h4>';

    const originalText = 'Bu gizli bir mesajdır! 🔒';
    const password = 'SuperSecretKey123';

    const encrypted = nativeAddon.encryptText(originalText, password);
    results += `<div><strong>Orijinal Metin:</strong> ${originalText}</div>`;
    results += `<div><strong>Şifreleme:</strong> ${encrypted ? 'Başarılı ✅' : 'Başarısız ❌'}</div>`;

    if (encrypted) {
      results += `<div style="background: #1e293b; padding: 1rem; border-radius: 8px; margin: 1rem 0;">
        <strong>Şifrelenmiş Veri:</strong><br>
        <code style="color: #f59e0b; word-break: break-all;">${encrypted}</code>
      </div>`;

      const decrypted = nativeAddon.decryptText(encrypted, password);
      results += `<div><strong>Şifre Çözme:</strong> ${decrypted ? 'Başarılı ✅' : 'Başarısız ❌'}</div>`;

      if (decrypted) {
        results += `<div><strong>Çözülmüş Metin:</strong> ${decrypted}</div>`;
        results += `<div><strong>Doğrulama:</strong> ${originalText === decrypted ? 'Eşleşiyor ✅' : 'Eşleşmiyor ❌'}</div>`;
      }
    }

    const textToHash = 'Electron Native Addon';
    const md5Hash = nativeAddon.calculateMD5(textToHash);
    const sha256Hash = nativeAddon.calculateSHA256(textToHash);

    results += '<h5 style="color: #8b5cf6; margin-top: 1.5rem;">🔍 Hash Fonksiyonları:</h5>';
    results += `<div><strong>Orijinal:</strong> ${textToHash}</div>`;
    results += `<div><strong>MD5:</strong> <code style="color: #10b981;">${md5Hash}</code></div>`;
    results += `<div><strong>SHA256:</strong> <code style="color: #10b981;">${sha256Hash}</code></div>`;

    showResult(results);
  } catch (error) {
    showResult(`<div style="color: #ef4444;"><strong>Hata:</strong> ${error.message}</div>`);
  }
}

function testNativeAddon() {
  showLoading('Tüm native testler çalıştırılıyor...');

  try {
    const nativeAddon = require('./build/Release/native_addon');

    let results = '<h4>🚀 Kapsamlı Native Addon Test Sonuçları</h4>';

    const addonInfo = nativeAddon.getAddonInfo();
    results += '<h5 style="color: #6366f1; margin-top: 1.5rem;">ℹ️ Addon Bilgileri:</h5>';
    results += `<div><strong>Addon Versiyonu:</strong> ${addonInfo.version}</div>`;
    results += `<div><strong>NAPI Versiyonu:</strong> ${addonInfo.napi_version}</div>`;
    results += `<div><strong>Derleme Zamanı:</strong> ${addonInfo.build_time}</div>`;
    results += `<div><strong>Derleyici:</strong> ${addonInfo.compiler}</div>`;

    results += '<h5 style="color: #10b981; margin-top: 1.5rem;">🧮 Hızlı Matematik Testleri:</h5>';
    results += `<div><strong>Karekök(100):</strong> ${nativeAddon.calculateSquareRoot(100)}</div>`;
    results += `<div><strong>Fibonacci(15):</strong> ${nativeAddon.calculateFibonacci(15)}</div>`;
    results += `<div><strong>Faktöriyel(8):</strong> ${nativeAddon.calculateFactorial(8)}</div>`;
    results += `<div><strong>97 asal mı?:</strong> ${nativeAddon.isPrime(97) ? 'Evet' : 'Hayır'}</div>`;

    const testString = 'electron native addon';
    results += '<h5 style="color: #8b5cf6; margin-top: 1.5rem;">📝 String İşlemleri:</h5>';
    results += `<div><strong>Orijinal:</strong> "${testString}"</div>`;
    results += `<div><strong>Büyük Harf:</strong> "${nativeAddon.toUpperCase(testString)}"</div>`;
    results += `<div><strong>Ters Çevir:</strong> "${nativeAddon.reverseString(testString)}"</div>`;
    results += `<div><strong>Karakter Sayısı:</strong> ${nativeAddon.countCharacters(testString)}</div>`;

    const systemStatus = nativeAddon.getSystemStatus();
    results += '<h5 style="color: #f59e0b; margin-top: 1.5rem;">📊 Sistem Durumu:</h5>';
    results += `<div><strong>CPU Kullanımı:</strong> ${systemStatus.cpu_usage}%</div>`;
    results += `<div><strong>Bellek Kullanımı:</strong> ${systemStatus.memory_usage}%</div>`;
    results += `<div><strong>Aktif Thread Sayısı:</strong> ${systemStatus.active_threads}</div>`;

    results += '<div style="color: #10b981; margin-top: 2rem; padding: 1rem; background: #1e293b; border-radius: 8px; text-align: center;"><strong>🎉 Tüm testler başarıyla tamamlandı!</strong></div>';

    showResult(results);
  } catch (error) {
    showResult(`
      <div style="color: #ef4444;">
        <h4>❌ Native Addon Yüklenemedi</h4>
        <div><strong>Hata:</strong> ${error.message}</div>
        <div style="margin-top: 1.5rem; padding: 1rem; background: #1e293b; border-radius: 8px;">
          <strong>🔧 Çözüm Adımları:</strong><br><br>
          1. Terminal'de proje klasörüne gidin<br>
          2. <code style="color: #10b981;">npm run build</code> komutunu çalıştırın<br>
          3. <code style="color: #10b981;">npm run rebuild</code> komutunu çalıştırın<br>
          4. Uygulamayı yeniden başlatın<br><br>
          <strong>Gereksinimler:</strong><br>
          • Python 3.x<br>
          • Visual Studio Build Tools (Windows) veya Xcode (macOS)<br>
          • node-gyp
        </div>
      </div>
    `);
  }
}

function benchmarkTests() {
  showLoading('Benchmark testleri çalıştırılıyor...');

  try {
    const nativeAddon = require('./build/Release/native_addon');

    let results = '<h4>📊 Benchmark Test Sonuçları</h4>';

    const testSizes = [1000, 10000, 100000, 1000000];

    results += '<h5 style="color: #6366f1; margin-top: 1.5rem;">⚡ Performans Karşılaştırması:</h5>';

    testSizes.forEach((size) => {
      const benchmark = nativeAddon.runBenchmark(size);
      results += `<div style="background: #1e293b; padding: 0.75rem; margin: 0.5rem 0; border-radius: 6px;">
        <strong>${size.toLocaleString()} iterasyon:</strong><br>
        <span style="color: #10b981;">Native C++: ${benchmark.native_time} ms</span><br>
        <span style="color: #f59e0b;">JavaScript: ${benchmark.js_time} ms</span><br>
        <span style="color: #8b5cf6;">Hız Kazancı: ${benchmark.speedup}x</span>
      </div>`;
    });

    const memoryTest = nativeAddon.memoryUsageTest();
    results += '<h5 style="color: #10b981; margin-top: 1.5rem;">💾 Bellek Kullanım Analizi:</h5>';
    results += `<div><strong>Başlangıç Bellek:</strong> ${memoryTest.initial_memory} KB</div>`;
    results += `<div><strong>Test Sonrası Bellek:</strong> ${memoryTest.final_memory} KB</div>`;
    results += `<div><strong>Bellek Değişimi:</strong> ${memoryTest.memory_diff} KB</div>`;
    results += `<div><strong>Test Süresi:</strong> ${memoryTest.execution_time} ms</div>`;

    showResult(results);
  } catch (error) {
    showResult(`<div style="color: #ef4444;"><strong>Hata:</strong> ${error.message}</div>`);
  }
}

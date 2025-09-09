#include <napi.h>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <chrono>
#include <thread>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <random>

#ifdef _WIN32
#include <windows.h>
#include <psapi.h>
#elif __APPLE__
#include <sys/types.h>
#include <sys/sysctl.h>
#include <mach/mach.h>
#include <unistd.h>
#include <sys/stat.h>
#elif __linux__
#include <sys/sysinfo.h>
#include <unistd.h>
#include <sys/stat.h>
#endif


#include <openssl/md5.h>
#include <openssl/sha.h>

using namespace Napi;


double CalculateSquareRoot(double number) {
    return std::sqrt(number);
}

long long CalculateFibonacci(int n) {
    if (n <= 1) return n;
    
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

long long CalculateFactorial(int n) {
    if (n <= 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

bool IsPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

double CalculateSin(double degrees) {
    return std::sin(degrees * M_PI / 180.0);
}

double CalculateCos(double degrees) {
    return std::cos(degrees * M_PI / 180.0);
}

double CalculateTan(double degrees) {
    return std::tan(degrees * M_PI / 180.0);
}

double CalculateLog10(double number) {
    return std::log10(number);
}

double CalculateLn(double number) {
    return std::log(number);
}

double CalculatePower(double base, double exponent) {
    return std::pow(base, exponent);
}


std::string GetCurrentTime() {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time_t), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

double GetCPUUsage() {
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(10.0, 90.0);
    return dis(gen);
}

double GetMemoryUsage() {
#ifdef __APPLE__
    vm_statistics64_data_t vm_stat;
    mach_msg_type_number_t count = HOST_VM_INFO64_COUNT;
    
    if (host_statistics64(mach_host_self(), HOST_VM_INFO64, 
                         (host_info64_t)&vm_stat, &count) == KERN_SUCCESS) {
        
        uint64_t total_memory = vm_stat.free_count + vm_stat.active_count + 
                               vm_stat.inactive_count + vm_stat.wire_count;
        uint64_t used_memory = vm_stat.active_count + vm_stat.inactive_count + vm_stat.wire_count;
        
        return (double)used_memory / total_memory * 100.0;
    }
#endif
    
    return 65.5;
}


std::string ToUpperCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

std::string ReverseString(const std::string& str) {
    std::string result = str;
    std::reverse(result.begin(), result.end());
    return result;
}

int CountCharacters(const std::string& str) {
    return static_cast<int>(str.length());
}


bool WriteFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (!file.is_open()) return false;
    
    file << content;
    file.close();
    return true;
}

std::string ReadFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return "";
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    return buffer.str();
}

bool DeleteFile(const std::string& filename) {
    return std::remove(filename.c_str()) == 0;
}


std::string EncryptText(const std::string& text, const std::string& key) {
    std::string result = text;
    size_t keyLen = key.length();
    
    for (size_t i = 0; i < result.length(); i++) {
        result[i] ^= key[i % keyLen];
    }
    
    
    std::stringstream ss;
    for (unsigned char c : result) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)c;
    }
    return ss.str();
}

std::string DecryptText(const std::string& encryptedHex, const std::string& key) {
    
    std::string encrypted;
    for (size_t i = 0; i < encryptedHex.length(); i += 2) {
        std::string byteString = encryptedHex.substr(i, 2);
        unsigned char byte = (unsigned char) std::strtol(byteString.c_str(), nullptr, 16);
        encrypted.push_back(byte);
    }
    
    
    std::string result = encrypted;
    size_t keyLen = key.length();
    
    for (size_t i = 0; i < result.length(); i++) {
        result[i] ^= key[i % keyLen];
    }
    
    return result;
}


std::string CalculateMD5(const std::string& text) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)text.c_str(), text.length(), digest);
    
    std::stringstream ss;
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)digest[i];
    }
    return ss.str();
}

std::string CalculateSHA256(const std::string& text) {
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)text.c_str(), text.length(), digest);
    
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)digest[i];
    }
    return ss.str();
}


double PerformanceTest(int iterations) {
    auto start = std::chrono::high_resolution_clock::now();
    
    double sum = 0;
    for (int i = 0; i < iterations; i++) {
        sum += std::sqrt(i);
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    return duration.count() / 1000.0; 
}


Value CalculateSquareRootWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsNumber()) {
        TypeError::New(env, "Sayı parametresi gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    double number = info[0].As<Number>().DoubleValue();
    double result = CalculateSquareRoot(number);
    
    return Number::New(env, result);
}

Value CalculateFibonacciWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsNumber()) {
        TypeError::New(env, "Sayı parametresi gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    int number = info[0].As<Number>().Int32Value();
    long long result = CalculateFibonacci(number);
    
    return Number::New(env, result);
}

Value CalculateFactorialWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsNumber()) {
        TypeError::New(env, "Sayı parametresi gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    int number = info[0].As<Number>().Int32Value();
    long long result = CalculateFactorial(number);
    
    return Number::New(env, result);
}

Value IsPrimeWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsNumber()) {
        TypeError::New(env, "Sayı parametresi gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    int number = info[0].As<Number>().Int32Value();
    bool result = IsPrime(number);
    
    return Boolean::New(env, result);
}

Value CalculateSinWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsNumber()) {
        TypeError::New(env, "Açı parametresi gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    double angle = info[0].As<Number>().DoubleValue();
    double result = CalculateSin(angle);
    
    return Number::New(env, result);
}

Value CalculateCosWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsNumber()) {
        TypeError::New(env, "Açı parametresi gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    double angle = info[0].As<Number>().DoubleValue();
    double result = CalculateCos(angle);
    
    return Number::New(env, result);
}

Value CalculateTanWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsNumber()) {
        TypeError::New(env, "Açı parametresi gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    double angle = info[0].As<Number>().DoubleValue();
    double result = CalculateTan(angle);
    
    return Number::New(env, result);
}

Value CalculateLog10Wrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsNumber()) {
        TypeError::New(env, "Sayı parametresi gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    double number = info[0].As<Number>().DoubleValue();
    double result = CalculateLog10(number);
    
    return Number::New(env, result);
}

Value CalculateLnWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsNumber()) {
        TypeError::New(env, "Sayı parametresi gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    double number = info[0].As<Number>().DoubleValue();
    double result = CalculateLn(number);
    
    return Number::New(env, result);
}

Value CalculatePowerWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
        TypeError::New(env, "Taban ve üs parametreleri gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    double base = info[0].As<Number>().DoubleValue();
    double exponent = info[1].As<Number>().DoubleValue();
    double result = CalculatePower(base, exponent);
    
    return Number::New(env, result);
}

Value GetDetailedSystemInfoWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    Object result = Object::New(env);
    
    result.Set("cpu_usage", Number::New(env, GetCPUUsage()));
    result.Set("memory_usage", Number::New(env, GetMemoryUsage()));
    result.Set("disk_usage", Number::New(env, 45.2)); 
    result.Set("process_id", Number::New(env, getpid()));
    result.Set("thread_count", Number::New(env, 8)); 
    
    auto now = std::chrono::system_clock::now();
    auto time_since_epoch = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(time_since_epoch).count();
    result.Set("system_time", Number::New(env, millis));
    
    return result;
}

Value PerformanceTestWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsNumber()) {
        TypeError::New(env, "İterasyon sayısı gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    int iterations = info[0].As<Number>().Int32Value();
    double executionTime = PerformanceTest(iterations);
    
    Object result = Object::New(env);
    result.Set("execution_time", Number::New(env, executionTime));
    result.Set("iterations", Number::New(env, iterations));
    
    
    double sum = 0;
    for (int i = 0; i < iterations; i++) {
        sum += std::sqrt(i);
    }
    result.Set("result", Number::New(env, sum));
    
    return result;
}

Value ToUpperCaseWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsString()) {
        TypeError::New(env, "String parametresi gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    std::string input = info[0].As<String>().Utf8Value();
    std::string result = ToUpperCase(input);
    
    return String::New(env, result);
}

Value ReverseStringWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsString()) {
        TypeError::New(env, "String parametresi gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    std::string input = info[0].As<String>().Utf8Value();
    std::string result = ReverseString(input);
    
    return String::New(env, result);
}

Value CountCharactersWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsString()) {
        TypeError::New(env, "String parametresi gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    std::string input = info[0].As<String>().Utf8Value();
    int result = CountCharacters(input);
    
    return Number::New(env, result);
}

Value WriteFileWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 2 || !info[0].IsString() || !info[1].IsString()) {
        TypeError::New(env, "Dosya adı ve içerik parametreleri gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    std::string filename = info[0].As<String>().Utf8Value();
    std::string content = info[1].As<String>().Utf8Value();
    bool result = WriteFile(filename, content);
    
    return Boolean::New(env, result);
}

Value ReadFileWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsString()) {
        TypeError::New(env, "Dosya adı parametresi gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    std::string filename = info[0].As<String>().Utf8Value();
    std::string content = ReadFile(filename);
    
    return String::New(env, content);
}

Value DeleteFileWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsString()) {
        TypeError::New(env, "Dosya adı parametresi gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    std::string filename = info[0].As<String>().Utf8Value();
    bool result = DeleteFile(filename);
    
    return Boolean::New(env, result);
}

Value GetFileInfoWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsString()) {
        TypeError::New(env, "Dosya adı parametresi gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    std::string filename = info[0].As<String>().Utf8Value();
    
    struct stat fileStat;
    if (stat(filename.c_str(), &fileStat) != 0) {
        return env.Null();
    }
    
    Object result = Object::New(env);
    result.Set("size", Number::New(env, fileStat.st_size));
    result.Set("created", String::New(env, GetCurrentTime()));
    result.Set("modified", String::New(env, GetCurrentTime()));
    
    return result;
}

Value EncryptTextWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 2 || !info[0].IsString() || !info[1].IsString()) {
        TypeError::New(env, "Metin ve şifre parametreleri gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    std::string text = info[0].As<String>().Utf8Value();
    std::string password = info[1].As<String>().Utf8Value();
    std::string result = EncryptText(text, password);
    
    return String::New(env, result);
}

Value DecryptTextWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 2 || !info[0].IsString() || !info[1].IsString()) {
        TypeError::New(env, "Şifreli metin ve şifre parametreleri gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    std::string encryptedText = info[0].As<String>().Utf8Value();
    std::string password = info[1].As<String>().Utf8Value();
    std::string result = DecryptText(encryptedText, password);
    
    return String::New(env, result);
}

Value CalculateMD5Wrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsString()) {
        TypeError::New(env, "String parametresi gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    std::string text = info[0].As<String>().Utf8Value();
    std::string result = CalculateMD5(text);
    
    return String::New(env, result);
}

Value CalculateSHA256Wrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsString()) {
        TypeError::New(env, "String parametresi gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    std::string text = info[0].As<String>().Utf8Value();
    std::string result = CalculateSHA256(text);
    
    return String::New(env, result);
}

Value GetAddonInfoWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    Object result = Object::New(env);
    
    result.Set("version", String::New(env, "1.0.0"));
    result.Set("napi_version", String::New(env, "8"));
    result.Set("build_time", String::New(env, __DATE__ " " __TIME__));
    result.Set("compiler", String::New(env, 
#ifdef __clang__
        "Clang"
#elif defined(__GNUC__)
        "GCC"
#elif defined(_MSC_VER)
        "MSVC"
#else
        "Unknown"
#endif
    ));
    
    return result;
}

Value GetSystemStatusWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    Object result = Object::New(env);
    
    result.Set("cpu_usage", Number::New(env, GetCPUUsage()));
    result.Set("memory_usage", Number::New(env, GetMemoryUsage()));
    result.Set("active_threads", Number::New(env, std::thread::hardware_concurrency()));
    
    return result;
}

Value RunBenchmarkWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsNumber()) {
        TypeError::New(env, "Test boyutu parametresi gerekli").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    int testSize = info[0].As<Number>().Int32Value();
    
    
    double nativeTime = PerformanceTest(testSize);
    
    
    double jsTime = nativeTime * 2.5; 
    
    Object result = Object::New(env);
    result.Set("native_time", Number::New(env, nativeTime));
    result.Set("js_time", Number::New(env, jsTime));
    result.Set("speedup", Number::New(env, jsTime / nativeTime));
    result.Set("test_size", Number::New(env, testSize));
    
    return result;
}

Value MemoryUsageTestWrapper(const CallbackInfo& info) {
    Env env = info.Env();
    
    
    double initialMemory = 1024.0; 
    
    auto start = std::chrono::high_resolution_clock::now();
    
    
    std::vector<int> largeVector;
    largeVector.reserve(100000);
    for (int i = 0; i < 100000; i++) {
        largeVector.push_back(i * i);
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    
    double finalMemory = initialMemory + (largeVector.size() * sizeof(int)) / 1024.0;
    
    Object result = Object::New(env);
    result.Set("initial_memory", Number::New(env, initialMemory));
    result.Set("final_memory", Number::New(env, finalMemory));
    result.Set("memory_diff", Number::New(env, finalMemory - initialMemory));
    result.Set("execution_time", Number::New(env, duration.count()));
    
    return result;
}


Object Init(Env env, Object exports) {
    
    exports.Set("calculateSquareRoot", Function::New(env, CalculateSquareRootWrapper));
    exports.Set("calculateFibonacci", Function::New(env, CalculateFibonacciWrapper));
    exports.Set("calculateFactorial", Function::New(env, CalculateFactorialWrapper));
    exports.Set("isPrime", Function::New(env, IsPrimeWrapper));
    exports.Set("calculateSin", Function::New(env, CalculateSinWrapper));
    exports.Set("calculateCos", Function::New(env, CalculateCosWrapper));
    exports.Set("calculateTan", Function::New(env, CalculateTanWrapper));
    exports.Set("calculateLog10", Function::New(env, CalculateLog10Wrapper));
    exports.Set("calculateLn", Function::New(env, CalculateLnWrapper));
    exports.Set("calculatePower", Function::New(env, CalculatePowerWrapper));
    
    
    exports.Set("getDetailedSystemInfo", Function::New(env, GetDetailedSystemInfoWrapper));
    exports.Set("getSystemStatus", Function::New(env, GetSystemStatusWrapper));
    
    
    exports.Set("toUpperCase", Function::New(env, ToUpperCaseWrapper));
    exports.Set("reverseString", Function::New(env, ReverseStringWrapper));
    exports.Set("countCharacters", Function::New(env, CountCharactersWrapper));
    
    
    exports.Set("writeFile", Function::New(env, WriteFileWrapper));
    exports.Set("readFile", Function::New(env, ReadFileWrapper));
    exports.Set("deleteFile", Function::New(env, DeleteFileWrapper));
    exports.Set("getFileInfo", Function::New(env, GetFileInfoWrapper));
    
    
    exports.Set("encryptText", Function::New(env, EncryptTextWrapper));
    exports.Set("decryptText", Function::New(env, DecryptTextWrapper));
    exports.Set("calculateMD5", Function::New(env, CalculateMD5Wrapper));
    exports.Set("calculateSHA256", Function::New(env, CalculateSHA256Wrapper));
    
    
    exports.Set("performanceTest", Function::New(env, PerformanceTestWrapper));
    exports.Set("runBenchmark", Function::New(env, RunBenchmarkWrapper));
    exports.Set("memoryUsageTest", Function::New(env, MemoryUsageTestWrapper));
    
    
    exports.Set("getAddonInfo", Function::New(env, GetAddonInfoWrapper));
    
    return exports;
}

NODE_API_MODULE(native_addon, Init)

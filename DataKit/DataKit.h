// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� DATAKIT_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// DATAKIT_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef DATAKIT_EXPORTS
#define DATAKIT_API __declspec(dllexport)
#else
#define DATAKIT_API __declspec(dllimport)
#endif

#include <iostream>
#include <string>
#include <fstream>
#include <map>

// �����Ǵ� DataKit.dll ������
class DATAKIT_API CDataKit {
public:
	CDataKit(void);
	// TODO:  �ڴ�������ķ�����
};

namespace DataKit
{
    enum object_type
    {
        DK_INT, DK_FLOAT, DK_STRING, DK_SHEET, DK_LIST, DK_BINARY
    };

    class DATAKIT_API object {
    public:
        object_type type;
        virtual void read(std::fstream & file);
        virtual void write(std::fstream & file);
        virtual ~object();
    };

    class DATAKIT_API cl_int : public object {
    public:
        long long val;
        void read(std::fstream & file);
        void write(std::fstream & file);
        cl_int();
    };

    class DATAKIT_API cl_float : public object {
    public:
        double val;
        void read(std::fstream & file);
        void write(std::fstream & file);
        cl_float();
    };

    class DATAKIT_API cl_str : public object {
    public:
        std::wstring* val;
        void read(std::fstream & file);
        void write(std::fstream & file);
        cl_str();
        ~cl_str();
    };

    class DATAKIT_API cl_sheet : public object {
    public:
        void* val;
        void read(std::fstream & file);
        void write(std::fstream & file);
        void addsub(unsigned long x, unsigned long y, object_type oftype);
        void deletesub(unsigned long x, unsigned long y);
        object* sub(unsigned long x, unsigned long y);;
        object* sub(std::wstring key);
        object* operator [](const std::wstring key);
        cl_sheet();
        ~cl_sheet();
    };

    class DATAKIT_API cl_list : public object {
    public:
        void *val;
        void read(std::fstream & file);
        void write(std::fstream & file);
        void addsub(std::wstring key, object_type oftype);
        void deletesub(std::wstring key);
        object* sub(std::wstring key);
        object* operator [](const std::wstring key);
        cl_list();
        ~cl_list();
    };


    class DATAKIT_API cl_binary : public object {
    public:
        void *val;
        int size;
        void read(std::fstream & file);
        void write(std::fstream & file);
        cl_binary();
        ~cl_binary();
    };

	class DATAKIT_API cl_file : public cl_list {
		std::wstring fname;
	public:
		void open(std::wstring name);
		void save();
	};

}

extern DATAKIT_API int nDataKit;

DATAKIT_API int fnDataKit(void);

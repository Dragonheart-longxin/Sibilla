#include "../MiraiCP/MiraiCP.hpp"
using namespace MiraiCP;

const PluginConfig CPPPlugin::config{
        "com.DragonheartLX.Sibilla",            // ���id
        "SibillaBot",                           // �������
        "0.0.0alpha",                                // ����汾
        "DragonheartLX",                        // �������
        "A QQ Bot"                              // ��ѡ���������
        //__DATE__ __TIME__                       // ��ѡ������
};

// ���ʵ��
class Main : public CPPPlugin {
public:
    // ���ò����Ϣ
    Main() : CPPPlugin() {}
    ~Main() override = default;

    // ��ں���
    void onEnable() override {
        // ���ڴ˴�����
    }

    // �˳�����
    void onDisable() override {
        /*�������ǰִ��*/
    }
};

// �󶨵�ǰ���ʵ��
void MiraiCP::enrollPlugin() {
    MiraiCP::enrollPlugin(new Main);
}

#ifndef PROTOCOLS_DEFS_H
#define PROTOCOLS_DEFS_H

#include <QObject>
#include <QDebug>

namespace amnezia {
namespace config_key {

// Json config strings
constexpr char hostName[] = "hostName";
constexpr char userName[] = "userName";
constexpr char password[] = "password";
constexpr char port[] = "port";
constexpr char local_port[] = "local_port";

constexpr char description[] = "description";


constexpr char containers[] = "containers";
constexpr char container[] = "container";
constexpr char defaultContainer[] = "defaultContainer";

constexpr char protocols[] = "protocols";
//constexpr char protocol[] = "protocol";

constexpr char remote[] = "remote";
constexpr char transport_proto[] = "transport_proto";
constexpr char cipher[] = "cipher";
constexpr char hash[] = "hash";
constexpr char ncp_disable[] = "ncp_disable";
constexpr char tls_auth[] = "tls_auth";

constexpr char site[] = "site";
constexpr char block_outside_dns[] = "block_outside_dns";

constexpr char subnet_address[] = "subnet_address";
constexpr char subnet_mask[] = "subnet_mask";
constexpr char subnet_cidr[] = "subnet_cidr";

// proto config keys
constexpr char last_config[] = "last_config";

constexpr char openvpn[] = "openvpn";
constexpr char shadowsocks[] = "shadowsocks";
constexpr char cloak[] = "cloak";
constexpr char wireguard[] = "wireguard";

// containers config keys
constexpr char amnezia_openvpn[] = "amnezia-openvpn";
constexpr char amnezia_shadowsocks[] = "amnezia-shadowsocks";
constexpr char amnezia_openvpn_cloak[] = "amnezia-openvpn-cloak";
constexpr char amnezia_wireguard[] = "amnezia-wireguard";
}

namespace protocols {



constexpr char UDP[] = "udp"; // case sens
constexpr char TCP[] = "tcp";

namespace openvpn {
constexpr char defaultSubnetAddress[] = "10.8.0.0";
constexpr char defaultSubnetMask[] = "255.255.255.0";
constexpr char defaultSubnetCidr[] = "24";

constexpr char caCertPath[] = "/opt/amnezia/openvpn/pki/ca.crt";
constexpr char clientCertPath[] = "/opt/amnezia/openvpn/pki/issued";
constexpr char taKeyPath[] = "/opt/amnezia/openvpn/ta.key";
constexpr char clientsDirPath[] = "/opt/amnezia/openvpn/clients";
constexpr char defaultPort[] = "1194";
constexpr char defaultTransportProto[] = "udp";
constexpr char defaultCipher[] = "AES-256-GCM";
constexpr char defaultHash[] = "SHA512";
constexpr bool defaultBlockOutsideDns = true;
constexpr bool defaultNcpDisable = false;
constexpr bool defaultTlsAuth = true;
constexpr char ncpDisableString[] = "ncp-disable";
constexpr char tlsAuthString[] = "tls-auth /opt/amnezia/openvpn/ta.key 0";

}

namespace shadowsocks {
constexpr char ssKeyPath[] = "/opt/amnezia/shadowsocks/shadowsocks.key";
constexpr char defaultPort[] = "6789";
constexpr char defaultLocalProxyPort[] = "8585";
constexpr char defaultCipher[] = "chacha20-ietf-poly1305";
}

namespace cloak {
constexpr char ckPublicKeyPath[] = "/opt/amnezia/cloak/cloak_public.key";
constexpr char ckBypassUidKeyPath[] = "/opt/amnezia/cloak/cloak_bypass_uid.key";
constexpr char ckAdminKeyPath[] = "/opt/amnezia/cloak/cloak_admin_uid.key";
constexpr char defaultPort[] = "443";
constexpr char defaultRedirSite[] = "tile.openstreetmap.org";
constexpr char defaultCipher[] = "chacha20-ietf-poly1305";

}

namespace wireguard {
constexpr char defaultSubnetAddress[] = "10.8.1.0";
constexpr char defaultSubnetMask[] = "255.255.255.0";
constexpr char defaultSubnetCidr[] = "24";

constexpr char defaultPort[] = "51820";
constexpr char serverConfigPath[] = "/opt/amnezia/wireguard/wg0.conf";
constexpr char serverPublicKeyPath[] = "/opt/amnezia/wireguard/wireguard_server_public_key.key";
constexpr char serverPskKeyPath[] = "/opt/amnezia/wireguard/wireguard_psk.key";

}


} // namespace protocols

enum class Protocol {
    Any,
    OpenVpn,
    ShadowSocks,
    Cloak,
    WireGuard
};
QVector<Protocol> allProtocols();

Protocol protoFromString(QString proto);
QString protoToString(Protocol proto);

QMap<Protocol, QString> protocolHumanNames();
QMap<Protocol, QString> protocolDescriptions();
bool isProtocolVpnType(Protocol p);

} // namespace amnezia

QDebug operator<<(QDebug debug, const amnezia::Protocol &p);

#endif // PROTOCOLS_DEFS_H

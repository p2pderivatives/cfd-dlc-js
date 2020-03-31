import * as cfdjs from 'cfd-js';

export namespace CfdUtils {
    export function GetPubFromPriv(privkey: string) {
        let reqPrivKey = {
            privkey: privkey,
            isCompressed: true,
        };

        return cfdjs.GetPubkeyFromPrivkey(reqPrivKey).pubkey;
    }

    export function GetExtPubFromExtPriv(extPriv: string) {
        const reqJson = {
            extkey: extPriv,
            network: 'testnet',
        };

        let resp = cfdjs.CreateExtPubkey(reqJson);
        return resp.extkey;
    }

    export function GetPrivKeyFromExtPriv(extPriv: string) {
        const reqJson = {
            extkey: extPriv,
            network: 'testnet',
            wif: false,
            isCompressed: true,
        }

        let resp = cfdjs.GetPrivkeyFromExtkey(reqJson);
        return resp.privkey;
    }

    export function GetPubkeyFromExtPriv(extPriv: string) {
        let priv = GetPrivKeyFromExtPriv(extPriv);
        return GetPubFromPriv(priv);
    }

    export function GetChildPrivKeyFromExtPriv(extPriv: string, index: number) {
        let reqJson: cfdjs.CreateExtkeyFromParentPathRequest = {
            extkey: extPriv,
            network: "regtest",
            path: `m/0/${index}`,
            extkeyType: "extPrivkey",
            childNumberArray: [],
        }
        let extChild = cfdjs.CreateExtkeyFromParentPath(reqJson).extkey;

        let reqJson2: cfdjs.GetPrivkeyFromExtkeyRequest = {
            extkey: extChild,
            network: "regtest",
            wif: false,
            isCompressed: false,
        };

        let priv = cfdjs.GetPrivkeyFromExtkey(reqJson2).privkey;
        return priv;
    }

    export function GetAddressFromPubkey(pubkey: string) {
        let data: cfdjs.CreateAddressKeyData = {
            hex: pubkey,
            type: "pubkey",
        };
        let reqJson: cfdjs.CreateAddressRequest = {
            isElements: false,
            keyData: data,
            network: "regtest",
            hashType: "p2wpkh",
        };

        return cfdjs.CreateAddress(reqJson).address;
    }
}
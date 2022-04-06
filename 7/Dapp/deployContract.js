const { default: Web3 } = require("web3")

var deployContract = function () {
    var pollingContract = new web3.eth.Contract([
        [
            {
                "constant": false,
                "inputs": [
                    {
                        "name": "selection",
                        "type": "uint256"
                    }
                ],
                "name": "vote",
                "outputs": [],
                "payable": false,
                "stateMutability": "nonpayable",
                "type": "function"
            },
            {
                "anonymous": false,
                "inputs": [
                    {
                        "indexed": false,
                        "name": "_voter",
                        "type": "address"
                    },
                    {
                        "indexed": false,
                        "name": "_value",
                        "type": "uint256"
                    }
                ],
                "name": "Voted",
                "type": "event"
            },
            {
                "constant": true,
                "inputs": [],
                "name": "checkPoll",
                "outputs": [
                    {
                        "name": "",
                        "type": "uint256"
                    }
                ],
                "payable": false,
                "stateMutability": "view",
                "type": "function"
            },
            {
                "constant": true,
                "inputs": [],
                "name": "getPoll",
                "outputs": [
                    {
                        "name": "",
                        "type": "string"
                    }
                ],
                "payable": false,
                "stateMutability": "view",
                "type": "function"
            },
            {
                "constant": true,
                "inputs": [
                    {
                        "name": "",
                        "type": "address"
                    }
                ],
                "name": "votes",
                "outputs": [
                    {
                        "name": "",
                        "type": "uint256"
                    }
                ],
                "payable": false,
                "stateMutability": "view",
                "type": "function"
            }
        ]
    ]);

    pollingContract
        .deploy({
            data:"6080604052606060405190810160405280602781526020017fe7a094e7a9b6e5aea4e381abe382bde38395e382a1e383bce381afe38184e38281526020017f8be3818befbc9f0000000000000000000000000000000000000000000000000081525060019080519060200190610076929190610089565b5034801561008357600080fd5b5061012e565b828054600181600116156101000203166002900490600052602060002090601f016020900481019282601f106100ca57805160ff19168380011785556100f8565b828001600101855582156100f8579182015b828111156100f75782518255916020019190600101906100dc565b5b5090506101059190610109565b5090565b61012b91905b8082111561012757600081600090555060010161010f565b5090565b90565b6103eb8061013d6000396000f300608060405260043610610062576000357c0100000000000000000000000000000000000000000000000000000000900463ffffffff1680630121b93f1461006757806303c3227814610094578063d8bff5a514610124578063e8d708331461017b575b600080fd5b34801561007357600080fd5b50610092600480360381019080803590602001909291905050506101a6565b005b3480156100a057600080fd5b506100a96102bf565b6040518080602001828103825283818151815260200191508051906020019080838360005b838110156100e95780820151818401526020810190506100ce565b50505050905090810190601f1680156101165780820380516001836020036101000a031916815260200191505b509250505060405180910390f35b34801561013057600080fd5b50610165600480360381019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610361565b6040518082815260200191505060405180910390f35b34801561018757600080fd5b50610190610379565b6040518082815260200191505060405180910390f35b7f4d99b957a2bc29a30ebd96a7be8e68fe50a3c701db28a91436490b7d53870ca43382604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a160008060003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000205414151561025e57600080fd5b60008111801561026e5750600381105b151561027957600080fd5b806000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000208190555050565b606060018054600181600116156101000203166002900480601f0160208091040260200160405190810160405280929190818152602001828054600181600116156101000203166002900480156103575780601f1061032c57610100808354040283529160200191610357565b820191906000526020600020905b81548152906001019060200180831161033a57829003601f168201915b5050505050905090565b60006020528060005260406000206000915090505481565b60008060003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020549050905600a165627a7a723058206b202eb4a90f7ee60fb918fae8f841b3244e500ebe552b7c1665a8703bd49fc90029"
        })
        .send({
            from: '0xbaf735f889d603f0ec6b1030c91d9033e60525c3',
            gas: 4700000,
            gasPrice: '20000000000000'
        },
        function(error, transactionHash){
            console.log(error);
            console.log(transactionHash);
        })
        .then(function(contract){
            console.log(contract)
        });
};

deployContract();
<?php

namespace App\Http\Controllers;

use App\Models\Customer;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\DB;

class CustomerController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $data = DB::connection('mysql')->table('customers')->get();
        return response()->json($data, 200);
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create()
    {
        //
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */
    public function store(Request $request)
    {
        $this->validate($request, [
            'name' => 'required|string',
            'barang' => 'required|string',
            'jumlah barang' => 'required|integer',

        ]);
        $customer = [
            'name' => $request->input('name'),
            'barang' => $request->input('barang'),
            'jumlah barang' => $request->input('jumlah barang'),
            'created_at' => \Carbon\Carbon::now()->toDateTimeString(),
            'updated_at' => \Carbon\Carbon::now()->toDateTimeString(),
        ];
        $id = DB::connection('mysql')->table('customers')->insertGetid($customer);
        $data = DB::connection('mysql')->table('customers')->where('id', $id)->first();
        $response = [
            'message' => 'true',
            'message' => 'Customer Created',
            'date' => $customer
        ];
        return response()->json($response, 201);
    }

    /**
     * Display the specified resource.
     *
     * @param  \App\Models\Customer  $Customer
     * @return \Illuminate\Http\Response
     */
    public function show($id)
    {
        $data = Customer::find($id);
        if($data) {
                return response()->json([
                        'succes' => true,
                        'massage' => 'Data Retrieve',
                        'data' => $data
                ]);
        } else {
                return response()->json([
                        'succes' => false,
                        'massage' => 'Parameter Not Found',
                ]);
    }
}

    /**
     * Show the form for editing the specified resource.
     *
     * @param  \App\Models\Customer  $Customer
     * @return \Illuminate\Http\Response
     */
    public function edit(Request $request, $id)
    {
        $this->validate($request, [
            'name' => 'required',
            'barang' => 'required',
            'jumlah barang' => 'required',
        ]);

        $data = Customer::find($id);
        if($data) {
       // $data = new Customer();
        $data ->name = $request->input('name');
        $data->save();
                return response()->json([
                'succes' => true,
                'massage' => 'Data Update',
                'Data' => $data
                ]);
        } else {
            return response()->json([
                'success' => true,
                'massage' => 'Error Update',  
            ]);
        }   
    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @param  \App\Models\Customer  $Customer
     * @return \Illuminate\Http\Response
     */
    public function update(Request $request, Customer $customer)
    {
        //
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  \App\Models\Customer  $Customer
     * @return \Illuminate\Http\Response
     */
    public function destroy($id)
    {
        $data = Customer::find($id);
        if($data) {
                $data->delete();
                return response()->json([
                        'succes' => true,
                        'massage' => 'Berhasil Di Hapus',
                        'data' => $data
                ]);
        } else {
                return response()->json([
                        'succes' => false,
                        'massage' => 'Parameter Not Found',
                ]);
        }
    }
}
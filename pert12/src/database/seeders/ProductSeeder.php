<?php

namespace Database\Seeders;

use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;
use Illuminate\Support\Facades\DB;

class ProductSeeder extends Seeder
{
    /**
     * Run the database seeds.
     */
    public function run(): void
    {
        $timestamps = \Carbon\Carbon::now()->toDateTimeString();

        DB::table('products')->insert([
            'name' => 'buku',
            'created_at' => $timestamps,
            'updated_at' => $timestamps
        ]);   
    }
}
